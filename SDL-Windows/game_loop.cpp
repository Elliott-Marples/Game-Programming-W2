#include "game_loop.h"
#include "SDL.h"
#include "utils.h"
#include <cstdio>

// Global Keys Array
bool gKeys[MAX_KEYS];

void Init(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Input(bool* done) {
	SDL_Event _event;

	while (SDL_PollEvent(&_event)) {
		if (_event.type == SDL_QUIT) {
			*done = true;
		}

		if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL) {
			switch (_event.key.keysym.sym) {
			case SDLK_ESCAPE:
				*done = true;
				break;

			case SDLK_w:
				printf("W has been pressed \n");
				gKeys[SDLK_w] = true;
				break;
			}
		}

		if (_event.type == SDL_KEYUP && _event.key.repeat == NULL) {
			switch (_event.key.keysym.sym) {
			case SDLK_w:
				gKeys[SDLK_w] = false;
			}
		}
	}
}

void Update() {

}

void Render(SDL_Renderer* renderer, int ScreenWidth, int ScreenHeight) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Define Window Center
	int windowCenterX = ScreenWidth / 2;
	int windowCenterY = ScreenHeight / 2;

	DRAW_TRIANGLE(renderer, 5, windowCenterX, windowCenterY);
}

void Destroy(SDL_Renderer* renderer, SDL_Window* window) {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}

	if (window) {
		SDL_DestroyWindow(window);
	}
}