#pragma once

#include <string>

using namespace std;

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	CLOSE_PROGRAM_EVENT,
	TOGGLE_FPS_EVENT,
	NUM_EVENT_TYPES //Keep this as the last
};

const string EVENT_NAMES[NUM_EVENT_TYPES] = {
	"End_Game_Event",
	"Toggle_FPS_Event",
};

class Event
{
public:
	Event(EventType type);
	virtual ~Event();

	EventType getType() const { return mType; };
	const string& getEventName() const;

private:
	EventType mType;
};