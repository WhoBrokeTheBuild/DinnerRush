#pragma once

#ifndef UPDATE_EVENT_DATA_H
#define UPDATE_EVENT_DATA_H

#include "Event.h"
#include "TimeInfo.h"

class UpdateEventData :
	public EventData
{
public:

	UpdateEventData(TimeInfo& timeInfo) :
		m_TimeInfo(timeInfo)
	{ }

	virtual inline string getClassName(void) const { return "Update Event Data"; }
	virtual inline EventData* clone(void) const { return New UpdateEventData(m_TimeInfo); }

	inline TimeInfo& getTimeInfo() const { return m_TimeInfo; }

private:

	TimeInfo& m_TimeInfo;

};

#endif // UPDATE_EVENT_DATA_H