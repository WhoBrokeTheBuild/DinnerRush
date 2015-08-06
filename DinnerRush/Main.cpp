
#include <cstdlib>
#include "Program.h"

int main(int argc, char* argv[]) 
{
	Program::Inst()->run();

	delete Program::Inst();

	return EXIT_SUCCESS;
}