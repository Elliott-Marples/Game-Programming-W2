// Related Header
#include "world.h"



// Global Variables
Square square;

// Constructor
World::World() {
	// Sets all pressed keys to false (not pressed)
	for (int i = 0; i < MAX_KEYS; i++) {
		pressedKeys[i] = false;
	}

	// Set pointers to nullptr before initialisation
	window = nullptr;
	renderer = nullptr;
}

// Initialisation
void World::Init() {
	window = SDL_CreateWindow("Game", 250, 250, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	square.Init(30, 30, 50, 50);
}

// Creates Game Loop
void World::Run() {
	while (!done) {
		timer.reset();

		Input();
		Update();
		Render();

		if (timer.get() < DELTA_TIME) {
			SDL_Delay(DELTA_TIME - timer.get());
		}
	}
}

// Input Handler
void World::Input() {
	while (SDL_PollEvent(&_event)) {
		if (_event.type == SDL_QUIT) {
			done = true;
		}

		if ((_event.type == SDL_KEYDOWN) && (_event.key.repeat = NULL)) {
			switch (_event.key.keysym.sym) {
				case SDLK_ESCAPE: {
					done = true;
					break;
				}

				case SDLK_w: {
					printf("W has been pressed \n");
					pressedKeys[SDLK_w] = true;
					break;
				}
			}
		}
	}
}

// Update Handler
void World::Update() {
	rect.x++;
}

// Render Handler
void World::Render() {
	// Clears screen to specified colour
	SDL_SetRenderDrawColor(renderer, 0, 0, 20, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	// Draws rectangle with specified colour
	square.Render(renderer);

	// Renders changes
	SDL_RenderPresent(renderer);
}

// Destroy renderer and window
void World::Destroy() {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}

	if (window) {
		SDL_DestroyWindow(window);
	}
}

// Quit
void World::Quit() {
	Destroy();
}