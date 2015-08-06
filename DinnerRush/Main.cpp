
#include <cstdlib>
#include "Program.h"

int main(int argc, char* argv[]) 
{
	Program *prog = new Program();
	prog->run();
	delete prog;

	return EXIT_SUCCESS;
}