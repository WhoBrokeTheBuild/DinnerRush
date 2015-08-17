
#include <cstdlib>
#include "Util.h"
#include "MemoryTracker.h"

#include "Program.h"

int main(int argc, char* argv[]) 
{
	MemoryTracker::Init();

	Program::Inst()->run();

	delete Program::Inst();

	if (MemoryTracker::AllocationCount() > 0)
	{
		MemoryTracker::PrintAllocations();
		pause();
	}

	MemoryTracker::Term();

	return EXIT_SUCCESS;
}