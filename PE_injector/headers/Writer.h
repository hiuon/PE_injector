#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int write_pe_header(char* out, const std::map<std::string, std::string>& data);

int write_sections(char* out, const std::vector<std::string>& data);

int write_imports(char* out, const std::vector<std::string>& data);