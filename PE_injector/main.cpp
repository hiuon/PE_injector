#include "./headers/Checker.h"
#include "./headers/Program.h"

int main(int argc, char* argv[]) {

	Program parser = Program(argc, argv);
	int e = parser.start();
	if (e != STATUS_OK) {
		std::cout << "ERROR CODE: " << e << ".\n";
	}
}