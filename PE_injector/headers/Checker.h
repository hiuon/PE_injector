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
	STATUS_ER_NOT_I386 = 40,
	STATUS_ER_DOTNET_FILE = 50,
	STATUS_ER_FILE_WITH_DS = 60,
	STATUS_ER_NOT_ENOUGH_FREE_SPACE = 70
};

const std::map<STATUS_CODE, std::string> st_code_str = {
	{STATUS_CODE::STATUS_OK, "OK"},
	{STATUS_CODE::STATUS_ER_WRITE, "ERROR WRITE"},
	{STATUS_CODE::STATUS_ER_READ, "ERROR READ"},
	{STATUS_CODE::STATUS_ER_PATH, "ERROR PATH"},
	{STATUS_CODE::STATUS_ER_PARAM, "ERROR PARAMETERES"},
	{STATUS_CODE::STATUS_ER_NOT_PE, "ERROR NOT PE FILE"},
	{STATUS_CODE::STATUS_ER_NOT_I386, "ERROR NOT 32 BIT PE"},
	{STATUS_CODE::STATUS_ER_DOTNET_FILE, "ERROR .NET FILE"},
	{STATUS_CODE::STATUS_ER_FILE_WITH_DS, "ERROR FILE WITH DIGITAL SIGNATURE"},
	{STATUS_CODE::STATUS_ER_NOT_ENOUGH_FREE_SPACE, "ERROR NOT ENOUGH FREE SPACE"}
};

STATUS_CODE check_params(int argc, char* argv[], char*& in, char*& out, bool& injector, bool& stealth, std::string& library_name);

STATUS_CODE check_file_for_inject(unsigned int virt_size, unsigned int size_raw_data, unsigned int number_of_imports);

