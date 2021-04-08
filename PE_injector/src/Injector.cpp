#include <iostream>
#include <fstream>
#include "../headers/Checker.h"
#include "../headers/Injector.h"
#include "../headers/Reader.h"

void get_char(unsigned int value, char* temp) {
	size_t index = 0;
	while (index < 4) {
		temp[index] = value % 256;
		value /= 256;
		index++;
	}

}

bool is_clear(char* str, int length) {
	for (size_t index = 0; index < length; ++index) {
		if (str[index] != '\0') return false;
	}
	return true;
}

STATUS_CODE inject(const std::string& input, const std::string& dll_name,unsigned int import_addr, unsigned int number_of_imports, unsigned int raw_data, unsigned int pointer_to_raw, unsigned int va_gl, unsigned int& pointer_to_section, unsigned int pe_start)
{
	char temp[2048] = { 0 };
	char check[2048] = { 0 };
	std::fstream in(input, std::ios::binary | std::ios::in | std::ios::out);
	in.seekg(import_addr);
	in.read(temp, number_of_imports*0x14);

	in.seekg(pointer_to_raw + raw_data - (number_of_imports + 2) * 0x14);
	in.read(check, (number_of_imports + 2) * 0x14);

	//mmmm.....
	if (!is_clear(check, 2048)) {
		return STATUS_CODE::STATUS_ER_NOT_ENOUGH_FREE_SPACE;
	}
	//mm...
	//add pointer to name
	char temp_char[4] = { 0 };
	get_char(import_addr + va_gl - pointer_to_raw, temp_char);
	temp[number_of_imports * 0x14 + 0xc] = temp_char[0];
	temp[number_of_imports * 0x14 + 0xc + 1] = temp_char[1];
	temp[number_of_imports * 0x14 + 0xc + 2] = temp_char[2];
	temp[number_of_imports * 0x14 + 0xc + 3] = temp_char[3];

	//write new table 
	in.seekg(pointer_to_raw + raw_data - (number_of_imports + 2) * 0x14);
	in.write(temp, (number_of_imports + 2)* 0x14);

	//change size of section
	in.seekg(pointer_to_section + 8);
	get_char(raw_data, temp_char);
	std::cout << temp_char[0] << temp_char[1] << temp_char[2] << temp_char[3];
	in.write(temp_char, 4);

	//change pointer to imprva
	in.seekg(pe_start + 0x80);
	get_char(raw_data - (number_of_imports + 2) * 0x14 + va_gl, temp_char);
	in.write(temp_char, 4);

	//change size of import table
	get_char((number_of_imports + 2) * 0x14, temp_char);
	in.write(temp_char, 4);
	


	//add name of dll
	in.seekg(import_addr);
	in.write(dll_name.c_str(), dll_name.size());
	

	

	return STATUS_CODE::STATUS_OK;
}