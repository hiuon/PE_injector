#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

enum STATUS_CODE {
	STATUS_OK = 0,
	STATUS_ER_PATH = 11,
	STATUS_ER_READ = 12,
	STATUS_ER_WRITE = 13,
	STATUS_ER_PARAM = 20,
	STATUS_ER_NOT_PE = 30
};

int check_params(int argc, char* argv[], char*& in, char*& out, bool& b);

