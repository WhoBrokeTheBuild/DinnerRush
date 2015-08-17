#include "Program.h"

#include <thread>
#include <chrono>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Benchmark.h"
#include "TimeInfo.h"
#include "DataLoader.h"
#include "Util.h"
#include "Font.h"
#include "Texture.h"
#include "RenderedTextBuffer.h"
#include "InputManager.h"

Program * Program::sp_Instance = nullptr;

Program* Program::Inst(void)
{
	if (sp_Instance == nullptr) {
		sp_Instance = new Program();
	}
	return sp_Instance;
}

Program::Program(void) :
	m_TargetFPS(),
	m_CurrentFPS(),
	m_UpdateInterval(),
	mp_DataLoader(nullptr),
	mp_Window(nullptr),
	mp_Renderer(nullptr),

	mp_MainFont(nullptr),
	mp_TextBuffer(nullptr)
{
	BENCH_START();

	if (SDL_Init(SDL_INIT_VIDEO)) {
		die("Failed to initialize SDL");
	}

	if (TTF_Init()) {
		die("Failed to initialize SDL TTF");
	}

	BENCH_PRINT("Program::ctor");
}

Program::~Program(void)
{
	delete mp_InputManager;
	mp_InputManager = NULL;

	TTF_Quit();
	SDL_Quit();
}

void Program::init(void)
{
	BENCH_START();

	createWindow();

	setTargetFPS(60.0);

	mp_DataLoader = new DataLoader();
	mp_DataLoader->loadData("GameData.bin");

	mp_DataLoader->saveData("GameData.out.txt");
	mp_DataLoader->saveData("GameData.out.bin");

	mp_MainFont = new Font(getDataLoader()->getString("AssetPath") + getDataLoader()->getString("MainFont"), 50);
	mp_TextBuffer = new RenderedTextBuffer(mp_MainFont, "Hello, World!", Color{ 255, 255, 255, 255 });

	BENCH_PRINT("Program::init");

	mp_InputManager = new InputManager;
}

void Program::term(void)
{
	BENCH_START();

	delete mp_TextBuffer;
	delete mp_MainFont;

	delete mp_DataLoader;

	destroyWindow();

	BENCH_PRINT("Program::term");
}

void Program::run(void)
{
	init();

	TimeInfo timeInfo;
	unsigned long long frameCount = 0;

	auto startTime = std::chrono::high_resolution_clock::now();
	auto lastTime = startTime;

	double secsSinceLastFrame = 0;

	bool running = true;
	while (running)
	{
		auto time = std::chrono::high_resolution_clock::now();
		auto elapsedTime = time - lastTime;
		lastTime = time;

		timeInfo.ElapsedSeconds = std::chrono::duration_cast<std::chrono::duration<double>>(elapsedTime).count();
		timeInfo.ElapsedMilliseconds = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(elapsedTime).count();
		timeInfo.TotalSeconds += timeInfo.ElapsedSeconds;
		timeInfo.TotalMilliseconds += timeInfo.ElapsedMilliseconds;

		timeInfo.Delta = timeInfo.ElapsedSeconds / m_UpdateInterval;

		secsSinceLastFrame += timeInfo.ElapsedSeconds;

		update(timeInfo);

		if (secsSinceLastFrame >= m_UpdateInterval) {
			render();
			++frameCount;
			m_CurrentFPS = (m_UpdateInterval / secsSinceLastFrame) * m_TargetFPS;
			
			secsSinceLastFrame = 0;
		}

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
	}

	term();
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

void Program::update(TimeInfo& timeInfo)
{
	std::cout << m_CurrentFPS << " " << timeInfo.Delta << std::endl;
}

void Program::render(void)
{
	SDL_RenderClear(getSDLRenderer());

	mp_TextBuffer->getTexture()->render(getSDLRenderer(), 100, 100);

	SDL_RenderPresent(getSDLRenderer());
}

void Program::setTargetFPS(double fps)
{
	m_TargetFPS = fps;
	m_UpdateInterval = (1.0 / m_TargetFPS);
}

DataLoader* Program::getDataLoader(void) const
{
	return mp_DataLoader;
}

SDL_Window* Program::getSDLWindow(void) const
{
	return mp_Window;
}

SDL_Renderer* Program::getSDLRenderer(void) const
{
	return mp_Renderer;
}
