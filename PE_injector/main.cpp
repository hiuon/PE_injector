#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "./headers/Checker.h"
#include "./headers/Reader.h"
#include "./headers/Writer.h"
#include "./headers/Program.h"


int main(int argc, char* argv[]) {

	Program parser = Program(argc, argv);

	parser.start();
}