#include <iostream>
#include <fstream>
#include <vector>


int main(int argc, char* argv[]) {

	//check params
	std::string input_path;
	std::string output_path;
	//int e = Checker::check(argc, argv, input_path, output_path);

	//if smth wrong -> exit
	//if (e != 0) {
	//	return -1;
	//}

	//start read binary file
	std::ifstream in(input_path, std::ios::in | std::ios::binary);



	//necessary fields of pe file
	std::vector<std::string> fields{ "cputype","flags","imgbase","imagesize","subsystem", "exprva", "imprva" };
	std::vector<std::string> values{ "cputype","flags","imgbase","imagesize","subsystem", "exprva", "imprva" };

	//read file
	//Helper::read_binary(values, in, e);

	//write json file
	//Helper::write_to_json(output_path, fields, values);


	return 0;
}