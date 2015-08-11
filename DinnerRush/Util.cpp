#include "Util.h"

#include <cstdio>

void pause(void)
{
	printf("Press any key to continue\n");
	getchar();
}

void die(const string& msg) 
{
	printf("Error: %s\n", msg.c_str());
	pause();
	exit(1);
}

string getFileExt(const string& filename)
{
	if (filename.find_last_of(".") != std::string::npos)
		return filename.substr(filename.find_last_of(".") + 1);
	return "";
}
