#include "Animation.h"
#include "Event.h"
#include "UpdateEventData.h"

Animation::Animation(void) :
	m_Speed(0),
	m_CurrFrame(0),
	m_FrameNum(0),
	m_Loop(true),
	mp_Sprites(nullptr),
	m_MSUntilNextFrame()
{

}
Animation::Animation(const float& speed, const int& totalFrames, const bool& loop) :
	m_Speed(speed),
	m_CurrFrame(0),
	m_FrameNum(totalFrames),
	m_Loop(loop),
	mp_Sprites(nullptr),
	m_MSUntilNextFrame(speed)
{
	mp_Sprites = new Sprite*[totalFrames];
}

Animation::~Animation(void)
{
	for (int i = 0; i < m_FrameNum; i++)
	{
		if (mp_Sprites[i])
		{
			delete mp_Sprites[i];
			mp_Sprites[i] = nullptr;
		};
	}
	
	if (mp_Sprites)
	{
		delete mp_Sprites;
		mp_Sprites = nullptr;
	}
	
	//If add timer to class DELETE TIMER KTHNXBAI :)

}

void Animation::addSprite(Sprite* sprite)
{
	mp_Sprites[m_CurrFrame] = sprite;
	m_CurrFrame++;

	if (m_CurrFrame >= m_FrameNum)
		m_CurrFrame = 0;
}

Sprite* Animation::getSprite(void) const
{
	return mp_Sprites[m_CurrFrame];
}

void Animation::update(const Event& evt)
{
	UpdateEventData* pData = evt.getDataAs<UpdateEventData>();

	m_MSUntilNextFrame -= pData->getTimeInfo().ElapsedMilliseconds;

	if (m_MSUntilNextFrame <= 0)
	{
		nextFrame();
		m_MSUntilNextFrame = m_Speed;
	}
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
void Animation::goToFrame(const int& frame)
{
	int holdFrame = m_CurrFrame;
	m_CurrFrame = frame;
	if (m_CurrFrame >= m_FrameNum)
		m_CurrFrame = holdFrame;
	//else
		//ADD: Tmer->star
}