#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <filesystem>
#include "../headers/status_code.h"


class Program {
private:
	std::string input_path;
	std::string output_path;
	std::string library_name;
	bool is_injector = false;
	bool is_stealth = false;
	STATUS_CODE is_ok;
public:
	Program(int argc, char* argv[]);

	STATUS_CODE start();
};
