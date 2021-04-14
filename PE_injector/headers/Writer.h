#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "../headers/status_code.h"

STATUS_CODE write_pe_header(const std::string& out, const std::map<std::string, std::string>& data);

STATUS_CODE write_sections(const std::string& out, const std::vector<std::string>& data);

STATUS_CODE write_imports(const std::string& out, const std::vector<std::string>& data);