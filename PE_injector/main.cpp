#include "./headers/Checker.h"
#include "./headers/Program.h"

int main(int argc, char* argv[]) {

	Program parser = Program(argc, argv);
	STATUS_CODE e = parser.start();
	if (e != STATUS_CODE::STATUS_OK) {
		std::cout << "STATUS MESSAGE: " << st_code_str.at(e) << "\n";
		return -1;
	}

	return 0;
}