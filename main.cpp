// Standard Headers
#include <iostream> // Used for printing functions
#include <string> // Used for string functions

// Library Headers
#include "SDL.h"

// Project Headers
#include "world.h"
#include "timer.h"



// Global Variables
World world;

// Main Function
int main(int argc, char* argv[]) {
	// Returns if SDL cannot initialise
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 1;
	}

	// Starts World
	world.Init();
	world.Run();
	world.Quit();
	SDL_Quit();

	// Return after quitting
	return 0;
}