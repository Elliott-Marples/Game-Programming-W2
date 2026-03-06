#include "timer.h"
#include "SDL.h"

Timer::Timer() {
	start = 0;
};

void Timer::reset() {
	start = SDL_GetTicks();
}

int Timer::get() {
	return (SDL_GetTicks() - start);
}