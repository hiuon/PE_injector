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
	STATUS_CODE e = check_params(argc, argv, in, out, is_injector, is_stealth);
	if (e != STATUS_CODE::STATUS_OK) {
		is_ok = e;
	}
	else {
		is_ok = STATUS_CODE::STATUS_OK;
		input_path.assign(in);
		output_path.assign(out);
	}

}

enum class STATUS_CODE Program::start()
{
	if (is_ok != STATUS_CODE::STATUS_OK) return is_ok;
	PEFile pe = PEFile(input_path, output_path);
	if (is_injector) {
		return pe.Inject();
	}
	else {
		STATUS_CODE e = pe.Read();
		if (e != STATUS_CODE::STATUS_OK)
		{
			return e;
		}
		e = pe.Write();
		if (e != STATUS_CODE::STATUS_OK)
		{
			return e;
		}
	}
	return STATUS_CODE::STATUS_OK;
}
