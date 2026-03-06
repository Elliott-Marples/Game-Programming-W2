// Related Header
#include "timer.h"



// Constructor
Timer::Timer() {
	start = 0;
}

// Reset Ticks on Timer
void Timer::reset() {
	start = SDL_GetTicks();
}

// Get Ticks on Timer
int Timer::get() {
	return (SDL_GetTicks() - start);
}