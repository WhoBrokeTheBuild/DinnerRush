#pragma once

#ifndef FONT_H
#define FONT_H

#include "TrackedObject.h"
#include "Types.h"
#include <SDL_ttf.h>

#include "Texture.h"

class Font :
	public TrackedObject
{
public:

	Font(string filename, int size);

	~Font(void);

	virtual inline string getClassName(void) const { return "Font"; }

	Texture* renderText(string text, SDL_Color color);

private:

	TTF_Font	*mp_Font;

}; // Font

#endif // FONT_H