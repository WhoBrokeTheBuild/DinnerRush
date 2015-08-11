#pragma once

#ifndef PROGRAM_H
#define PROGRAM_H

#include "Types.h"
#include <SDL.h>

#include "DataLoader.h"
#include "Font.h"

class Program
{
public:

	static Program* Inst(void);

	Program(void);
	~Program(void);

	void run(void);

	void createWindow(void);
	void destroyWindow(void);

	void update(void);
	void render(void);

	DataLoader* getDataLoader(void);

	SDL_Window* getSDLWindow(void);
	SDL_Renderer* getSDLRenderer(void);

private:

	static Program  *sp_Instance;

	DataLoader      *mp_DataLoader;

	SDL_Window		*mp_Window;
	SDL_Renderer    *mp_Renderer;

	Font			*mp_MainFont;

}; // Program

#endif // PROGRAM_H