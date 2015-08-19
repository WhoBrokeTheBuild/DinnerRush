#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include "TrackedObject.h"

class Sprite;
class EventData;

class Animation : 
	public TrackedObject
{
public:

	Animation(void);
	Animation(const float& speed, const int& totalFrames, const bool& loop);

	~Animation(void);

	void addSprite(Sprite* sprite);
	Sprite* getSprite(void) const;

	void update(const Event& evt);

	float getSpeed(void) const { return m_Speed; }
	void setSpeed(float val) { m_Speed = val; }
	
	void nextFrame(void);
	void goToFrame(const int& frame);

private:

	int			m_CurrFrame, 
				m_FrameNum;

	/// The animation speed in milliseconds
	float		m_Speed;
	float		m_MSUntilNextFrame;

	bool		m_Loop;

	Sprite**	mp_Sprites; //array of sprites
};

#endif // ANIMATION_H