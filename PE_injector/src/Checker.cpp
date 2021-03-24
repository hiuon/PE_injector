#include "../headers/Checker.h"
#include <iostream>
#include <filesystem>

int Checker::check_params(int argc, char* argv[], char*& in, char*& out)
{
	if (argc < 3) {
		std::cout << "Not enough arguments. Bye...\n";
		return 4;
	}

	//check correct path
	if (!strcmp(argv[1], "-al")) {
		in = argv[2];
		out = argv[3];
		if (!std::filesystem::exists(in) || !std::filesystem::exists(out))
		{
			std::cout << "The file " << in << " or " << out << " doesn't exist. Bye...\n";
			return 1;
		}
	}
	else {
		in = argv[1];
		out = argv[2];
		if (!std::filesystem::exists(in))
		{
			std::cout << "The file " << in << " doesn't exist. Bye...\n";
			return 1;
		}
	}

	return 0;
}




