#pragma once

class Event;

class EventListener
{
public:
	EventListener();
	virtual ~EventListener();

	virtual void handleEvent(const Event& theEvent) = 0;

private:

};