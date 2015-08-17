#pragma once

#include <map>

class Event;
class EventListener;
enum EventType;

using namespace std;

class EventSystem
{
public:
	EventSystem();
	~EventSystem();

	void fireEvent(const Event& theEvent);
	void addListener(EventType type, EventListener* pListener);
	void removeListener(EventType type, EventListener* pListener);
	void removeListenerFromAllEvents(EventListener* pListener);


private:
	static EventSystem* msInstance;
	multimap<EventType, EventListener*> mListenerMap;
	void dispatchAllEvents(const Event& theEvent);
};

extern EventSystem* gpEventSystem;