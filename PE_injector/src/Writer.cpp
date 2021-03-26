#include "../headers/Writer.h"
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

int write_pe_header(char* out, const std::map<std::string, std::string>& data)
{
	std::fstream out_file(out, std::ios::out);
	out_file << "{\n";
	for (auto it = data.begin(); it != data.end(); ++it) {
		out_file << "\t\"" << it->first << "\" : \"" << it->second << "\",\n";
	}
	out_file.close();
	return 0;
}

int write_sections(char* out, const std::vector<std::string>& data)
{
	std::fstream out_file(out, std::ios::out | std::ios::app);
	out_file << "\t\"sections\" : \n\t[\n";
	for (size_t index = 0; index < data.size() - 1; ++index) {
		out_file << "\t\t\"" << data[index] << "\",\n";
	}
	out_file << "\t\t\"" << data.back() << "\"\n";
	out_file << "\t],\n\t\n";
	out_file.close();
	return 0;
}

int write_imports(char* out, const std::vector<std::string>& data)
{
	std::fstream out_file(out, std::ios::out | std::ios::app);
	out_file << "\t\"imports\" : \n\t[\n";
	for (size_t index = 0; index < data.size() - 1; ++index) {
		out_file << "\t\t\"" << data[index] << "\",\n";
	}
	out_file << "\t\t\"" << data.back() << "\"\n";
	out_file << "\t]\n}";
	out_file.close();
	return 0;
}