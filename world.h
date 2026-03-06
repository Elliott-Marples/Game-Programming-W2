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
#define FRAME_RATE 30
#define MOVE_LEFT 'w'



// Declarations
class World {
private:
	Timer timer;
	const int DELTA_TIME = FRAME_RATE;
	bool done = false;

public:
	World();
};



#endif // !GAME_WORLD_H_
