#include "Font.h"

#include <SDL_ttf.h>
#include "Texture.h"

Font::Font(string filename, int size) :
	mp_Font(nullptr)
{
	mp_Font = TTF_OpenFont(filename.c_str(), size);
	if (!mp_Font) {
		printf("Warning: Failed to load font %s\n", filename.c_str());
		return;
	}
}

Font::~Font(void)
{
	TTF_CloseFont(mp_Font);
}

Texture* Font::renderText(string text, SDL_Color color)
{
	SDL_Surface* surf = TTF_RenderText_Blended(mp_Font, text.c_str(), color);
	Texture* tex = new Texture(surf);

	SDL_FreeSurface(surf);

	return tex;
}
