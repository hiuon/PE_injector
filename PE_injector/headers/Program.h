#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <filesystem>


class Program {
private:
	std::string input_path;
	std::string output_path;
	std::string library_name;
	bool is_injector = false;
	bool is_stealth = false;
	enum class STATUS_CODE is_ok;
public:
	Program(int argc, char* argv[]);

	enum class STATUS_CODE start();
};
