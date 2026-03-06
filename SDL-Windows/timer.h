#include "SDL.h"

// Header Guard
#ifndef TIMER
#define TIMER

// Declarations
class Timer {
private:
	int start;

public:
	Timer();

	void reset();
	int get();
};

// End of Header Guard
#endif