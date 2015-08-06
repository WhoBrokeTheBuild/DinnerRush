#include "Program.h"

#include "Util.h"

Program::Program(void) :
	mp_Window(nullptr)
{
	SDL_Init(SDL_INIT_VIDEO);
}

Program::~Program(void)
{
	SDL_Quit();
}

void Program::run(void)
{
	createWindow();

	bool running = true;

	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}

		update();
		render();
	}

	destroyWindow();
}

void Program::createWindow(void)
{
	mp_Window = SDL_CreateWindow(
		"Dinner Rush - A Pathing AI Test",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1024,
		768,
		SDL_WINDOW_SHOWN
	);

	if (!mp_Window) {
		die("Failed to create window");
	}
}

void Program::destroyWindow(void)
{
	SDL_DestroyWindow(mp_Window);
}

void Program::update(void)
{
	
}

void Program::render(void)
{
	
}
