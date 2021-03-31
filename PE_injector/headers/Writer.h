#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

enum class STATUS_CODE write_pe_header(const std::string& out, const std::map<std::string, std::string>& data);

enum class STATUS_CODE write_sections(const std::string& out, const std::vector<std::string>& data);

enum class STATUS_CODE write_imports(const std::string& out, const std::vector<std::string>& data);