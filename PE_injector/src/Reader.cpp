#include "../headers/Reader.h"
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

unsigned int pe_start = 0;
unsigned int os_type = 0;

int read_pe_header(char* in_path, std::map<std::string, std::string>& data)
{
	std::ifstream in(in_path, std::ios::in | std::ios::binary);
	//4 byte buffer
	char temp[8] = { 0,0,0,0,0,0,0,0 };
	//read start of file
	in.read(temp, 2);

	//if not PE -> end
	if (temp[0] != 0x4d && temp[1] != 0x5a) {
		std::cout << "It is not PE file. Bye...\n";
		return 5;
	}

	//go to here
	in.seekg(0x3c);

	//read address of pe header
	in.read(temp, 4);

	//go to pe header
	pe_start = get_byte(temp);

	in.seekg(pe_start);

	//read cputype
	in.seekg(0x04, std::ios::cur);
	in.read(temp, 2);
	data["cputype"] = get_field(temp, 2);

	in.seekg(pe_start);

	//read flags
	in.seekg(0x16, std::ios::cur);
	in.read(temp, 2);
	data["flags"] = get_field(temp, 2);

	//add kostyl' )
	os_type = 4;
	if ((temp[1] & 0x01) == 0x01) {
		os_type = 0;
	}

	in.seekg(pe_start);

	//read imgbase (8 bytes - not 4) and smth types have format ulonglong (8 bytes) ->
	//other offset (no equal to pe.txt :: 64 bit machine) 
	//at 0x30
	in.seekg(0x34 - os_type, std::ios::cur);
	in.read(temp, 4 + os_type);
	data["imgbase"] = get_field(temp, 4 + os_type);

	in.seekg(pe_start);

	//read imgsize
	in.seekg(0x50, std::ios::cur);
	in.read(temp, 4);
	data["imgsize"] = get_field(temp, 4);

	in.seekg(pe_start);

	//read subsystem
	in.seekg(0x5c, std::ios::cur);
	in.read(temp, 2);
	data["subsystem"] = "0x" + to_hex(temp[1]) + to_hex(temp[0]);

	in.seekg(pe_start);

	//add 0x10 cause some (4) fields have ulonglong (8 byte) type
	//read exprva
	in.seekg(0x78 + os_type * 4, std::ios::cur);
	in.read(temp, 4);
	data["exprva"] = get_field(temp, 4);

	in.seekg(pe_start);
	//as well as read exprva add 0x10
	//read imprva
	in.seekg(0x80 + os_type * 4, std::ios::cur);
	in.read(temp, 4);
	data["imprva"] = get_field(temp, 4);


	in.close();

	return 0;
}

std::string to_hex(char t)
{
	std::stringstream ss;
	unsigned int i0 = (unsigned char)t;
	if (i0 < 16) ss << std::hex << 0;
	ss << std::hex << i0;
	return ss.str();
}

unsigned int get_byte(char* temp)
{
	unsigned int i3 = (unsigned char)temp[3];
	unsigned int i2 = (unsigned char)temp[2];
	unsigned int i1 = (unsigned char)temp[1];
	unsigned int i0 = (unsigned char)temp[0];

	i3 <<= 24;
	i2 <<= 16;
	i1 <<= 8;

	return i0 + i1 + i2 + i3;
}

std::string get_field(char* t, size_t size)
{
	std::stringstream ss;
	ss << "0x";
	for (size_t index = size - 1; index > 0; --index) {
		ss << to_hex(t[index]);
	}
	ss << to_hex(t[0]);
	return ss.str();
}

int read_sections(char* input, std::vector<std::string>& data) {
	std::ifstream in(input, std::ios::binary);
	char temp[8] = { 0,0,0,0,0,0,0,0 };

	in.seekg(pe_start);

	in.seekg(0x6, std::ios::cur);
	in.read(temp, 2);
	size_t num_sections = (temp[1] <<= 8) + temp[0];

	data.resize(num_sections);


	for (size_t index = 0; index < data.size(); ++index) {
		in.seekg(pe_start+index*0x28);
		in.seekg(0xf8, std::ios::cur);
		in.read(temp, 8);
		data[index] = temp;
	}
	in.close();
	return 0;
}