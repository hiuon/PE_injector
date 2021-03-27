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
	bool is_injector = false;
	int is_ok = true;
public:
	Program(int argc, char* argv[]);

	int start();
};
