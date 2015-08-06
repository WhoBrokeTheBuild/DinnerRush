#include "Program.h"

#include <SDL_ttf.h>
#include "Util.h"

Program * Program::sp_Instance = nullptr;

Program* Program::Inst(void)
{
	if (sp_Instance == nullptr) {
		sp_Instance = new Program();
	}
	return sp_Instance;
}

Program::Program(void) :
	mp_Window(nullptr),
	mp_Renderer(nullptr)
{
	if (SDL_Init(SDL_INIT_VIDEO)) {
		die("Failed to initialize SDL");
	}

	if (TTF_Init()) {
		die("Failed to initialize SDL TTF");
	}
}

Program::~Program(void)
{
	TTF_Quit();
	SDL_Quit();
}

void Program::run(void)
{
	createWindow();

	mp_MainFont = new Font("../Assets/Roboto.ttf", 50);

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
		SDL_Delay(16);
	}

	delete mp_MainFont;

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

	mp_Renderer = SDL_CreateRenderer(mp_Window, -1, SDL_RENDERER_ACCELERATED);
}

void Program::destroyWindow(void)
{
	SDL_DestroyRenderer(mp_Renderer);
	SDL_DestroyWindow(mp_Window);
}

void Program::update(void)
{
	
}

void Program::render(void)
{
	SDL_RenderClear(getSDLRenderer());

	Texture* pTex = mp_MainFont->renderText("Hello, World!", { 255, 255, 255, 255 });

	pTex->render(getSDLRenderer(), 100, 100);

	delete pTex;

	SDL_RenderPresent(getSDLRenderer());
}

SDL_Window* Program::getSDLWindow(void)
{
	return mp_Window;
}

SDL_Renderer* Program::getSDLRenderer(void)
{
	return mp_Renderer;
}
