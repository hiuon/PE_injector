#include "../headers/Checker.h"
#include "../headers/status_code.h"
#include <iostream>
#include <filesystem>
#include <vector>

void split(const std::string& s, char delim, std::vector<std::string>& elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

bool is_clear(char* str, int length) {
	for (size_t index = 0; index < length; ++index) {
		if (str[index] != '\0') return false;
	}
	return true;
}

STATUS_CODE check_params(int argc, char* argv[], char*& in, char *& out, bool& injector, bool& stealth, std::string& library_name)
{
	if (argc < 3) {
		std::cout << "Not enough arguments. Bye...\n";
		return STATUS_CODE::STATUS_ER_PARAM;
	}

	//check correct path
	if (!strcmp(argv[1], "-al")) {

		if (!std::filesystem::exists(argv[2]))
		{
			std::cout << "The file " << argv[2] << " doesn't exist. Bye...\n";
			
			return STATUS_CODE::STATUS_ER_PATH;
		}
		library_name.assign(argv[3]);
		std::vector<std::string> my_dll;
		split(library_name, '.', my_dll);
		if (!my_dll[1]._Equal("dll")) {
			std::cout << "Smth wrong with " << argv[3] << ". Bye...\n";
			return STATUS_CODE::STATUS_ER_PATH;
		}

		
		
		injector = true;
		in = argv[2];
		out = argv[3];

		if (argc > 4 && !strcmp(argv[4], "-stealth")) {
			stealth = true;
		}
		
	}
	else {
		if (!std::filesystem::exists(argv[1]))
		{
			std::cout << "The file " << argv[1] << " doesn't exist. Bye...\n";
			return STATUS_CODE::STATUS_ER_PATH;
		}
		injector = false;
		in = argv[1];
		out = argv[2];
	}

	return STATUS_CODE::STATUS_OK;
}

STATUS_CODE check_file_for_inject(unsigned int virt_size, unsigned int size_raw_data, unsigned int number_of_imports)
{
	if (size_raw_data - virt_size <= (number_of_imports + 1) * 0x14) {
		return STATUS_CODE::STATUS_ER_NOT_ENOUGH_FREE_SPACE;
	}
	return STATUS_CODE::STATUS_OK;
}

STATUS_CODE check_dot_net_and_signature(const std::string& in_path, unsigned int pe_start)
{
	std::fstream in(in_path, std::ios::binary | std::ios::in);
	char temp[8] = { 0 };
	in.seekg(pe_start + 0x98);
	in.read(temp, 8);
	if (!is_clear(temp, 8)) return STATUS_CODE::STATUS_ER_FILE_WITH_DS;

	in.seekg(pe_start + 0x80 + 0x68);
	in.read(temp, 8);
	if (!is_clear(temp, 8)) return STATUS_CODE::STATUS_ER_DOTNET_FILE;

	in.close();
	return STATUS_CODE::STATUS_OK;
}






