#include "../headers/Checker.h"
#include <iostream>
#include <filesystem>

int check_params(int argc, char* argv[], char*& in, char *& out, bool& b)
{
	if (argc < 3) {
		std::cout << "Not enough arguments. Bye...\n";
		return STATUS_ER_PARAM;
	}

	//check correct path
	if (!strcmp(argv[1], "-al")) {
		if (!std::filesystem::exists(argv[2]) || !std::filesystem::exists(argv[3]))
		{
			std::cout << "The file " << argv[2] << " or " << argv[3] << " doesn't exist. Bye...\n";
			return STATUS_ER_PATH;
		}
		b = true;
		in = argv[2];
		out = argv[3];
	}
	else {
		if (!std::filesystem::exists(argv[1]))
		{
			std::cout << "The file " << argv[1] << " doesn't exist. Bye...\n";
			return STATUS_ER_PATH;
		}
		b = false;
		in = argv[1];
		out = argv[2];
	}

	return STATUS_OK;
}




