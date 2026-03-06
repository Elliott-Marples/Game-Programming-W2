// Define Guard
#ifndef GAME_TIMER_H_
#define GAME_TIMER_H_

// Standard Headers
#include <iostream>

// Library Headers
#include "SDL.h"



// Declarations
class Timer {
private:
	int start; // Ticks on start of program

public:
	Timer(); // Constructor

	void reset(); // Resets ticks on timer
	int get(); // Gets ticks on timer
};



#endif // !GAME_TIMER_H_
