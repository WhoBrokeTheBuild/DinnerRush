#pragma once

#ifndef PROGRAM_H
#define PROGRAM_H

#include "Types.h"
#include <SDL.h>

class Program
{
public:

	Program(void);
	~Program(void);

	void run(void);

	void createWindow(void);
	void destroyWindow(void);

	void update(void);
	void render(void);

private:

	SDL_Window		*mp_Window;

}; // Program

#endif // PROGRAM_H