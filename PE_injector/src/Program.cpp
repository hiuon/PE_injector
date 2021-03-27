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
	if (int e = check_params(argc, argv, in, out, is_injector)) {
		is_ok = e;
	}
	else {
		input_path.assign(in);
		output_path.assign(out);
	}

}

int Program::start()
{
	if (is_ok) return is_ok;
	PEFile pe = PEFile(input_path, output_path);
	if (is_injector) {
		return pe.Inject();
	}
	else {
		int e = pe.Read();
		if (e != STATUS_OK)
		{
			return e;
		}
		e = pe.Write();
		if (e != STATUS_OK)
		{
			return e;
		}
	}
	return STATUS_OK;
}
