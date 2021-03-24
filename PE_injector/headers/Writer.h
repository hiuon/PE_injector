#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

int write_pe_header(char* out, std::map<std::string, std::string> data);