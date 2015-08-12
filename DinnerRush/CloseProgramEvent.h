#pragma once

#include "Event.h"

class CloseProgramEvent : public Event
{
public:
	CloseProgramEvent() : Event(CLOSE_PROGRAM_EVENT) {};
	~CloseProgramEvent() {};

};