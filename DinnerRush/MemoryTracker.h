#pragma once

#ifndef MEMORY_TRACKER_H
#define MEMORY_TRACKER_H

#include "Map.h"
#include <string>

using std::string;

class TrackedObject;

class MemoryTracker
{

	friend class TrackedObject;

public:

	static bool Init( void );
	static void Term( void );

	static bool AddAllocation( TrackedObject* pObject, size_t size, 
							   unsigned int lineNumber, string filename );
	static bool RemoveAllocation( TrackedObject* pObject );

	static inline unsigned int AllocationCount( void ) 
		{ return (unsigned int)s_Allocations.size(); }

	static void PrintAllocations( void );

private:

	struct AllocationRecord
	{
	public:

		unsigned int	Number,
						LineNumber;
		size_t			Size;
		string			Filename;

		AllocationRecord( int num, size_t size, int lineNum, string filename ) :
			Number(num),
			LineNumber(lineNum),
			Size(size),
			Filename(filename)
		{ }

	}; // struct AllocationRecord

	static Map<TrackedObject*, AllocationRecord>	s_Allocations;

	static unsigned int								s_AllocationIndex;

}; // class MemoryTracker

#endif // MEMORY_TRACKER_H