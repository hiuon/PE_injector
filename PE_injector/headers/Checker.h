#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "../headers/status_code.h"

STATUS_CODE check_params(int argc, char* argv[], char*& in, char*& out, bool& injector, bool& stealth, std::string& library_name);

STATUS_CODE check_file_for_inject(unsigned int virt_size, unsigned int size_raw_data, unsigned int number_of_imports);

STATUS_CODE check_dot_net_and_signature(const std::string& in_path, unsigned int pe_start);

bool is_clear(char* str, int length);

