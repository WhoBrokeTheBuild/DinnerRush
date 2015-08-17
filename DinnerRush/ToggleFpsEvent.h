#pragma once

#include "Event.h"

class ToggleFpsEvent : public Event
{
public:
	ToggleFpsEvent() : Event(TOGGLE_FPS_EVENT) {};
	~ToggleFpsEvent() {};

};