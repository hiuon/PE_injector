#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

class PEFile
{
private:
	std::string input_path;
	std::string output_path;
	std::map<std::string, std::string> data_pe_header;
	std::vector<std::string> data_sections;
	std::vector<std::string> data_imports;

	unsigned int pe_start;
	unsigned int os_type;
	unsigned int import_addr;
	unsigned int va_gl;
	unsigned int raw_gl;
public:
	PEFile(const std::string& in, const std::string& out);

	int Read();

	int Write();

	int Inject();

};

