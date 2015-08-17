#include "Texture.h"

#include "Util.h"
#include "Program.h"

Texture::Texture(void) :
	mp_Texture(nullptr)
{
}

Texture::Texture(string filename) :
	mp_Texture(nullptr)
{
	SDL_Surface* surf = nullptr;

	// TODO: Load texture from file

	mp_Texture = SDL_CreateTextureFromSurface(Program::Inst()->getSDLRenderer(), surf);
	SDL_FreeSurface(surf);

	if (!mp_Texture) {
		die("Failed to load texture from file");
	}
}

Texture::Texture(SDL_Surface* pSurface)
{
	mp_Texture = SDL_CreateTextureFromSurface(Program::Inst()->getSDLRenderer(), pSurface);

	if (!mp_Texture) {
		die("Failed to load texture from SDL_Surface");
	}
}

Texture::~Texture(void)
{
	SDL_DestroyTexture(mp_Texture);
}

void Texture::render(SDL_Renderer* pRenderer, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(mp_Texture, nullptr, nullptr, &dst.w, &dst.h);

	SDL_RenderCopy(pRenderer, mp_Texture, nullptr, &dst);
}

SDL_Texture* Texture::getSDLTexture(void) const
{
	return mp_Texture;
}
