#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int read_pe_header(const std::string& in_path, std::map<std::string, std::string>& data, unsigned int& os_type, unsigned int& import_addr, unsigned int& pe_start);

std::string to_hex(char t);

unsigned int get_byte(char* temp);

std::string get_field(char* t, size_t size);

int read_sections(const std::string& input, std::vector<std::string>& data, unsigned int pe_start, unsigned int& import_addr, unsigned int& va_gl, unsigned int& raw_gl);

int read_imports(const std::string& input, std::vector<std::string>& data, unsigned int import_addr, unsigned int va_gl, unsigned int raw_gl);

