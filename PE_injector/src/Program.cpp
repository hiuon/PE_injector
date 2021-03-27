#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "../headers/Program.h"
#include "../headers/Checker.h"
#include "../headers/PEFile.h"

Program::Program(int argc, char* argv[])
{
	char* in = nullptr;
	char* out = nullptr;
	if (check_params(argc, argv, in, out, is_injector)) {
		is_ok = false;
	};
	input_path.assign(in);
	output_path.assign(out);
}

int Program::start()
{
	PEFile pe = PEFile(input_path, output_path);
	if (is_injector) {
		return pe.Inject();
	}
	else {
		pe.Read();
		pe.Write();
	}
	return STATUS_OK;
}
