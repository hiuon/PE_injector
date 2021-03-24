#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "./headers/Checker.h"

enum STATUS_CODE
{
	STATUS_OK,
	STATUS_ER_PATH,
	STATUS_ER_READ,
	STATUS_ER_WRITE,
	STATUS_ER_PARAM
};

int main(int argc, char* argv[]) {

	//check params
	char* input_path = nullptr;
	char* output_path = nullptr;

	STATUS_CODE status;

	status = (STATUS_CODE)Checker::check_params(argc, argv, input_path, output_path);

	if (STATUS_OK != status) {
		return status;
	}

	//necessary fields of pe header
	std::map<std::string, std::string> data_pe_header = { {"cputype", ""}, {"flags", ""}, {"imgbase", ""}, {"imagesize", ""}, {"subsystem", ""}, {"exprva", ""}, {"imprva", ""} };


	//read file
	//Helper::read_binary(values, in, e);

	//write json file
	//Helper::write_to_json(output_path, fields, values);


	return 0;
}