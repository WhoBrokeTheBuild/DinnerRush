#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include "Types.h"

class Texture;

class Sprite
{
public:

	Sprite();

	~Sprite(void);

private:

	Texture		*mp_Texture;
	Rect        m_Area;

}; // Sprite

#endif // SPRITE_H