#include "../headers/Checker.h"
#include <iostream>
#include <filesystem>
#include <vector>

void split(const std::string& s, char delim, std::vector<std::string>& elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

STATUS_CODE check_params(int argc, char* argv[], char*& in, char *& out, bool& injector, bool& stealth, std::string& library_name)
{
	if (argc < 3) {
		std::cout << "Not enough arguments. Bye...\n";
		return STATUS_CODE::STATUS_ER_PARAM;
	}

	//check correct path
	if (!strcmp(argv[1], "-al")) {

		if (!std::filesystem::exists(argv[2]))
		{
			std::cout << "The file " << argv[2] << " doesn't exist. Bye...\n";
			
			return STATUS_CODE::STATUS_ER_PATH;
		}
		library_name.assign(argv[3]);
		std::vector<std::string> my_dll;
		split(library_name, '.', my_dll);
		if (!my_dll[1]._Equal("dll")) {
			std::cout << "Smth wrong with " << argv[3] << ". Bye...\n";
			return STATUS_CODE::STATUS_ER_PATH;
		}

		
		
		injector = true;
		in = argv[2];
		out = argv[3];

		if (argc > 4 && !strcmp(argv[4], "-stealth")) {
			stealth = true;
		}
		
	}
	else {
		if (!std::filesystem::exists(argv[1]))
		{
			std::cout << "The file " << argv[1] << " doesn't exist. Bye...\n";
			return STATUS_CODE::STATUS_ER_PATH;
		}
		injector = false;
		in = argv[1];
		out = argv[2];
	}

	return STATUS_CODE::STATUS_OK;
}

STATUS_CODE check_file_for_inject(unsigned int virt_size, unsigned int size_raw_data, unsigned int number_of_imports)
{
	if (size_raw_data - virt_size <= (number_of_imports + 1) * 0x14) {
		return STATUS_CODE::STATUS_ER_NOT_ENOUGH_FREE_SPACE;
	}
	return STATUS_CODE::STATUS_OK;
}






