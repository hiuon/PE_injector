#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

enum class STATUS_CODE {
	STATUS_OK = 0,
	STATUS_ER_PATH = 11,
	STATUS_ER_READ = 12,
	STATUS_ER_WRITE = 13,
	STATUS_ER_PARAM = 20,
	STATUS_ER_NOT_PE = 30,
	STATUS_ER_NOT_I386 = 40
};

const std::map<STATUS_CODE, std::string> st_code_str = {
	{STATUS_CODE::STATUS_OK, "OK"},
	{STATUS_CODE::STATUS_ER_WRITE, "ERROR WRITE"},
	{STATUS_CODE::STATUS_ER_READ, "ERROR READ"},
	{STATUS_CODE::STATUS_ER_PATH, "ERROR PATH"},
	{STATUS_CODE::STATUS_ER_PARAM, "ERROR PARAMETERES"},
	{STATUS_CODE::STATUS_ER_NOT_PE, "ERROR NOT PE FILE"},
	{STATUS_CODE::STATUS_ER_NOT_I386, "ERROR NOT 32 BIT PE"},
};

STATUS_CODE check_params(int argc, char* argv[], char*& in, char*& out, bool& b);

