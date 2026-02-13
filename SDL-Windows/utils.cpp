#include "utils.h"

#include "SDL.h"

void SET_CENTER_OF_DISPLAY(int windowWidth, int windowHeight, int* screenWidth, int* screenHeight) {
	SDL_DisplayMode display{};
	SDL_GetCurrentDisplayMode(0, &display);

	int centerX = (display.w / 2) - (windowWidth / 2);
	int centerY = (display.h / 2) - (windowHeight / 2);

	*screenWidth = centerX;
	*screenHeight = centerY;
}