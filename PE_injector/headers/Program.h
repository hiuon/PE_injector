#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class Program {
private:
	std::string input_path;
	std::string output_path;
	bool is_injector = false;
public:
	Program(char* in, char* out, bool b);

	void check();
};
