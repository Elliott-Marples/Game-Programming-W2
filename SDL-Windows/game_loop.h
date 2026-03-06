#include "SDL.h"

// Header Guard
#ifndef GAME_LOOP
#define GAME_LOOP

#define MAX_KEYS 256

// Declarations
extern bool gKeys[MAX_KEYS];

void Init(SDL_Renderer* renderer);

void Input(bool* done);

void Update();

void Render(SDL_Renderer* renderer, int ScreenWidth, int screenHeight);

void Destroy(SDL_Renderer* renderer, SDL_Window* window);

// End of Header Guard
#endif