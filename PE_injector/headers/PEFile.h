#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "../headers/status_code.h"

class PEFile
{
private:
	std::string input_path;
	std::string output_path;
	std::map<std::string, std::string> data_pe_header;
	std::vector<std::string> data_sections;
	std::vector<std::string> data_imports;

	unsigned int number_of_imports;
	unsigned int pe_start;
	unsigned int os_type;
	unsigned int import_addr;
	unsigned int va_gl;
	unsigned int raw_gl;
	unsigned int virt_size;
	unsigned int size_raw_data;
	unsigned int pointer_to_section;
public:
	PEFile(const std::string& in, const std::string& out);

	STATUS_CODE Read();

	STATUS_CODE Write();

	STATUS_CODE Inject(bool is_stealth);

};

