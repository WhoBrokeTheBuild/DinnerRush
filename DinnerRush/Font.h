#pragma once

#ifndef FONT_H
#define FONT_H

#include "Types.h"
#include <SDL_ttf.h>

class Texture;

class Font
{
public:

	Font(string filename, int size);

	~Font(void);

	Texture* renderText(string text, SDL_Color color);

private:

	TTF_Font	*mp_Font;

}; // Font

#endif // FONT_H