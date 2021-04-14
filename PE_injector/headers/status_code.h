#pragma once
#include <map>
#include <string>

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