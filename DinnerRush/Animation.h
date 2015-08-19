#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include "TrackedObject.h"

class Sprite;
class Event;

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

	double getSpeed(void) const { return m_Speed; }
	void setSpeed(double speed) { m_Speed = speed; }
	
	void nextFrame(void);
	void goToFrame(const int& frame);

private:

	int			m_CurrFrame, 
				m_FrameNum;

	/// The animation speed in milliseconds
	double		m_Speed,
				m_MSUntilNextFrame;

	bool		m_Loop;

	Sprite**	mp_Sprites; //array of sprites
};

#endif // ANIMATION_H