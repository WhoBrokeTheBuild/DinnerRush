#include "Util.h"

#include <cstdio>

void pause(void)
{
	printf("Press any key to continue\n");
	getchar();
}

void die(string msg) 
{
	printf("Error: %s\n", msg.c_str());
	pause();
	exit(1);
}