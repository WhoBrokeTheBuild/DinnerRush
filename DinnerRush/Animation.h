#pragma once
#include "MemoryTracker.h"
#include "Sprite.h"
#include "TimeInfo.h"

class Animation : public MemoryTracker
{
public:
	Animation();
	Animation(float fps, int totalFrames, bool loop);
	~Animation();

	void addSprite(Sprite* sprite);
	Sprite* getSprite();
	void update();
	

	//CLASS WORK IN PROGRESS 8/17/15


	float getFps() { return m_Fps; };
	void nextFrame();
	void goToFrame(int frame);

	//void handleEvent(const Event& theEvent);

private:
	int m_CurrFrame, m_FrameNum;
	float m_Fps;
	bool m_Loop;
	Sprite** m_pSprites; //array of sprites
};

