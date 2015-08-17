#include "Animation.h"
#include "EventSystem.h"


Animation::Animation()
{
	m_Fps = 0.5; m_CurrFrame = 0; m_FrameNum = 0;
	m_Loop = true;
	m_pSprites = NULL;

}
Animation::Animation(float fps, int totalFrames, bool loop)
{
	m_Fps = fps;
	m_CurrFrame = 0;
	m_FrameNum = totalFrames;
	m_Loop = loop;
	m_pSprites = new Sprite*[totalFrames];
}

Animation::~Animation()
{
	for (int i = 0; i < m_FrameNum; i++)
	{
		if (m_pSprites[i])
		{
			delete m_pSprites[i];
			m_pSprites[i] = NULL;
		};
	}
	
	if (m_pSprites)
	{
		delete m_pSprites;
		m_pSprites = NULL;
	}
	
	//If add timer to class DELETE TIMER K THNX :)

}

void Animation::addSprite(Sprite* sprite)
{
	m_pSprites[m_CurrFrame] = sprite;
	m_CurrFrame++;

	if (m_CurrFrame >= m_FrameNum)
		m_CurrFrame = 0;
}

Sprite* Animation::getSprite()
{
	return m_pSprites[m_CurrFrame];
}

void Animation::update()
{
	//TO DO ADD UPDATE it'll Look something like this
	/*
		if( AnimationPlaying || FPS == 0)
		{
			if(Timer is not running)
				start timer

			if(Timer->elapsedTime >= 1000 / fps
			    Switch to next frame of animation
		}
	
	*/

}

void Animation::nextFrame()
{
	m_CurrFrame++;
	if (m_CurrFrame >= m_FrameNum)
	{
		m_CurrFrame = 0;
		//if (!m_Loop)
			//ADD: PLAY IS FALSE

	}

	//ADD: Timer->Start
}
void Animation::goToFrame(int frame)
{
	int holdFrame = m_CurrFrame;
	m_CurrFrame = frame;
	if (m_CurrFrame >= m_FrameNum)
		m_CurrFrame = holdFrame;
	//else
		//ADD: Tmer->star
}