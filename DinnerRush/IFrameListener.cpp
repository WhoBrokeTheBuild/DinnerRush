#include "IFrameListener.h"
#include "Program.h"
#include "Event.h"

IFrameListener::IFrameListener(void)
{
	Program::Inst()->addEventListener(Program::EVT_UPDATE, this, &IFrameListener::update);
	Program::Inst()->addEventListener(Program::EVT_RENDER, this, &IFrameListener::render);
}

IFrameListener::~IFrameListener(void)
{
	Program::Inst()->removeEventListener(Program::EVT_UPDATE, this, &IFrameListener::update);
	Program::Inst()->removeEventListener(Program::EVT_RENDER, this, &IFrameListener::render);
}

void IFrameListener::update(const Event& evt)
{ }

void IFrameListener::render(const Event& evt)
{ }
