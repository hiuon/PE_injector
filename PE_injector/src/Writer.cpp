#include "../headers/Writer.h"
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

int write_pe_header(char* out, std::map<std::string, std::string> data)
{
	std::fstream out_file(out, std::ios::out);
	out_file << "{\n";
	for (auto it = data.begin(); it != data.end(); ++it) {
		out_file << "\t\"" << it->first << "\" : \"" << it->second << "\",\n";
	}
	out_file.close();
	return 0;
}