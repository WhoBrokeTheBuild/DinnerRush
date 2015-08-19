#pragma once

#ifndef IFRAME_LISTENER_H
#define IFRAME_LISTENER_H

class Event;

class IFrameListener
{
public:

	IFrameListener(void);
	virtual ~IFrameListener(void);

	virtual void update(const Event& evt);
	virtual void render(const Event& evt);
};

#endif // IFRAME_LISTENER_H