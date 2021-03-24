#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "./headers/Checker.h"
#include "./headers/Reader.h"
#include "./headers/Writer.h"

enum STATUS_CODE
{
	STATUS_OK,
	STATUS_ER_PATH,
	STATUS_ER_READ,
	STATUS_ER_WRITE,
	STATUS_ER_PARAM,
	STATUS_ER_NOT_PE
};

int main(int argc, char* argv[]) {

	//check params
	char* input_path = nullptr;
	char* output_path = nullptr;

	STATUS_CODE status = STATUS_OK;

	status = (STATUS_CODE)check_params(argc, argv, input_path, output_path);

	if (STATUS_OK != status) {
		return status;
	}

	//necessary fields of pe header
	std::map<std::string, std::string> data_pe_header = { {"cputype", ""}, {"flags", ""}, {"imgbase", ""}, {"imagesize", ""}, {"subsystem", ""}, {"exprva", ""}, {"imprva", ""} };


	//read file
	status = (STATUS_CODE)read_pe_header(input_path, data_pe_header);

	if (STATUS_OK != status) {
		return status;
	}

	//write json file
	status = (STATUS_CODE)write_pe_header(output_path, data_pe_header);

	if (STATUS_OK != status) {
		return status;
	}


	return 0;
}