#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int read_pe_header(char* in_path, std::map<std::string, std::string>& data);

std::string to_hex(char t);

unsigned int get_byte(char* temp);

std::string get_field(char* t, size_t size);
