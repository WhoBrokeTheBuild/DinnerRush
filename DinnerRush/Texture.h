#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include "Types.h"
#include <SDL.h>

class Texture
{
public:

	Texture(void);
	Texture(string filename);
	Texture(SDL_Surface* pSurface);

	~Texture(void);

	void render(SDL_Renderer* pRenderer, int x, int y);

	SDL_Texture* getSDLTexture();

private:

	SDL_Texture		*mp_Texture;

}; // Texture

#endif // TEXTURE_H