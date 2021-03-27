#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int write_pe_header(const std::string& out, const std::map<std::string, std::string>& data);

int write_sections(const std::string& out, const std::vector<std::string>& data);

int write_imports(const std::string& out, const std::vector<std::string>& data);