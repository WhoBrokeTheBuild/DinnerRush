#pragma once

#ifndef UNIT_H
#define UNIT_H

#include "IEventDispatcher.h"
#include "IFrameListener.h"
#include "TrackedObject.h"

class Event;
class Animation;

class Unit :
	public IEventDispatcher,
	public IFrameListener,
	public TrackedObject
{
public:

	Unit(void);
	Unit(Animation* animation);
	~Unit(void);

	virtual inline string getClassName(void) const { return "Unit"; }

	virtual void render(const Event& evt);
	virtual void update(const Event& evt);

private:

	Animation* mp_Anim;

}; // Unit

#endif // UNIT_H