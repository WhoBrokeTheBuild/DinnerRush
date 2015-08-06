#include <cstdlib>
#include <cstdio>

#include <SDL.h>

#include "Util.h"

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = nullptr;

	window = SDL_CreateWindow(
		"Dinner Rush - A Pathing AI Test",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1024,
		768,
		SDL_WINDOW_SHOWN
	);

	if (!window) {
		die("Failed to create window");
	}

	bool running = true;

	while (running) {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					running = false;
					break;
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return EXIT_SUCCESS;
}