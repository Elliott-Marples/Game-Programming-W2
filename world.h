// Define Guard
#ifndef GAME_WORLD_H_
#define GAME_WORLD_H_

// Standard Headers
#include <iostream>

// Library Headers
#include "SDL.h"

// Project Headers
#include "timer.h"
#include "square.h"

// Definitions
#define MAX_KEYS (256)
#define FRAME_RATE 1
#define MOVE_LEFT 'w'



// Declarations
class World {
private:
	Timer timer; // Timer object
	const int DELTA_TIME = 1000 / FRAME_RATE; // Sets frame rate
	bool done = false; // Loop boolean

public:
	// Constructor
	World();

	// SDL Properties
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event _event;

	// Rectangle Properties
	SDL_Rect rect;
	Square square;

	// Pre Game Loop Functions
	void Init(); // Initialises world
	void Run(); // Creates game loop

	// Keyboard Handler
	bool pressedKeys[MAX_KEYS]; // Array of pressed keys

	// Game Loop
	void Input();
	void Update();
	void Render();

	// Post Game Loop Functions
	void Destroy();
	void Quit();
};



#endif // !GAME_WORLD_H_
