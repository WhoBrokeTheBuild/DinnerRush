#include "IEventDispatcher.h"

ArrayList<IEventDispatcher*> IEventDispatcher::s_Dispatchers = ArrayList<IEventDispatcher*>();

IEventDispatcher::IEventDispatcher( void )
	: m_EventMap(),
	  m_Changed(false)
{
    s_Dispatchers.add(this);
}

IEventDispatcher::~IEventDispatcher( void )
{
    s_Dispatchers.remove(this);
    removeAllListeners();
}

void IEventDispatcher::addEventListener( const EventID& eventId, const EventDelegate& functionDelegate )
{
    if ( ! m_EventMap.containsKey(eventId))
        m_EventMap[eventId] = ArrayList<EventDelegate*>();

    unsigned int length = (unsigned int)m_EventMap[eventId].size();

    for(unsigned int i = 0; i < length; ++i)
    {
        if (m_EventMap[eventId][i] == nullptr)
            continue;
        if (*(m_EventMap[eventId][i]) == functionDelegate)
            return;
    }

    m_EventMap[eventId].add(New EventDelegate(functionDelegate));
}

void IEventDispatcher::removeEventListener( const EventID& eventId, const EventDelegate& functionDelegate )
{
    if ( ! m_EventMap.containsKey(eventId))
        return;

	unsigned int length = (unsigned int)m_EventMap[eventId].size();

    for(unsigned int i = 0; i < length; ++i)
    {
        if (m_EventMap[eventId][i] == nullptr)
            continue;
        if (*(m_EventMap[eventId][i]) == functionDelegate)
        {
            delete m_EventMap[eventId][i];
            m_EventMap[eventId][i] = nullptr;
            m_Changed = true;
            return;
        }
    }
}

void IEventDispatcher::removeEventListener( const EventID& eventId, void (*function)(const Event&) )
{
    removeEventListener(eventId, EventDelegate(function));
}

void IEventDispatcher::addEventListener( const EventID& eventId, void (*function)(const Event&) )
{
    addEventListener(eventId, EventDelegate(function));
}

void IEventDispatcher::removeAllListeners( void )
{
    Map<EventID, ArrayList<EventDelegate*>>::Iterator mapIt;
    ArrayList<EventDelegate*>::Iterator listIt;

    unsigned int length;
    for (mapIt = m_EventMap.begin(); mapIt != m_EventMap.end(); ++mapIt)
    {
        length = (unsigned int)mapIt->second.size();
        for (unsigned int i = 0; i < length; ++i)
        {
            if (mapIt->second[i] != nullptr)
            {
                delete mapIt->second[i];
                mapIt->second[i] = nullptr;
            }
        }
    }

    m_EventMap.clear();
}

void IEventDispatcher::removeAllListeners( const EventID& eventId )
{
    if ( ! m_EventMap.containsKey(eventId))
        return;

    unsigned int length = (unsigned int)m_EventMap[eventId].size();
    for(unsigned int i = 0; i < length; ++i)
    {
        if ( m_EventMap[eventId][i] != nullptr )
        {
            delete m_EventMap[eventId][i];
            m_EventMap[eventId][i] = nullptr;
        }
    }

    m_EventMap.removeAt(eventId);

    m_Changed = true;
}

void IEventDispatcher::dispatch( const Event& event )
{
    EventID id = event.getID();

    if ( ! m_EventMap.containsKey(id))
        return;

    Event tmp = Event(event);

    tmp.setTarget(this);

    unsigned int length = (unsigned int)m_EventMap[id].size();
    for(unsigned int i = 0; i < length; ++i)
    {
        if (m_EventMap[id][i] != nullptr)
            m_EventMap[id][i]->invoke(event);
    }
}

void IEventDispatcher::cleanMap( void )
{
    if ( ! m_Changed)
        return;

    bool needRepeat = true;
    Map<EventID, ArrayList<EventDelegate*>>::Iterator mapIt;
    ArrayList<EventDelegate*>* list;

    while (needRepeat)
    {
        needRepeat = false;
        for (mapIt = m_EventMap.begin(); !needRepeat && mapIt != m_EventMap.end(); ++mapIt)
        {
            list = &mapIt->second;
            for (unsigned int i = 0; !needRepeat && i < list->size(); ++i)
            {
                if (list->at(i) == nullptr)
                {
                    list->removeAt(i);
                    needRepeat = true;
                    break;
                }
            }
        }
    }

    m_Changed = false;
}

