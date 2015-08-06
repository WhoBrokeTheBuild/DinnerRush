#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "Texture.h"

class Sprite
{
public:

	Sprite();

	~Sprite(void);

private:

	Texture		*mp_Texture;
	SDL_Rect    m_Area;

}; // Sprite

#endif // SPRITE_H