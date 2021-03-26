#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "../headers/Program.h"

Program::Program(char* in, char* out, bool b)
{
	input_path.assign(in);
	output_path.assign(out);
	is_injector = b;
}

void Program::check()
{
	std::cout << input_path << '\n' << output_path << '\n' << is_injector;
}