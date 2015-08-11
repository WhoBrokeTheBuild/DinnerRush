#include "Program.h"

#include <SDL_ttf.h>
#include "Util.h"
#include "DataLoader.h"

#include "Benchmark.h"

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
	BENCH_START();

	if (SDL_Init(SDL_INIT_VIDEO)) {
		die("Failed to initialize SDL");
	}

	if (TTF_Init()) {
		die("Failed to initialize SDL TTF");
	}

	mp_DataLoader = new DataLoader();
	mp_DataLoader->loadData("GameData.txt");
	mp_MainFont = new Font(getDataLoader()->getString("AssetPath") + getDataLoader()->getString("MainFont"), 50);

	BENCH_PRINT("Program::ctor");
}

Program::~Program(void)
{
	delete mp_DataLoader;

	TTF_Quit();
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
		SDL_Delay(16);
	}

	delete mp_MainFont;

	destroyWindow();
}

void Program::createWindow(void)
{
	BENCH_START();

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

	BENCH_PRINT("Program::createWindow");
}

void Program::destroyWindow(void)
{
	BENCH_START();

	SDL_DestroyRenderer(mp_Renderer);
	SDL_DestroyWindow(mp_Window);

	BENCH_PRINT("Program::destroyWindow");
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

DataLoader* Program::getDataLoader(void)
{
	return mp_DataLoader;
}

SDL_Window* Program::getSDLWindow(void)
{
	return mp_Window;
}

SDL_Renderer* Program::getSDLRenderer(void)
{
	return mp_Renderer;
}
