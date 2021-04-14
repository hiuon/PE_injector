#pragma once
#include "../headers/status_code.h"
STATUS_CODE inject(const std::string& input, const std::string& dll_name, unsigned int import_addr, unsigned int number_of_imports, unsigned int virt_size, unsigned int pointer_to_raw, unsigned int va_gl, unsigned int& pointer_to_section, unsigned int pe_start);
