#include "SDL.h"

// Header Guard
#ifndef UTILS
#define UTILS

// Declarations
void SET_CENTER_OF_DISPLAY(int windowWidth, int windowHeight, int* screenWidth, int* screenHeight);

void DRAW_TRIANGLE(SDL_Renderer* renderer, int triangleSideLength, int windowCenterX, int windowCenterY);

void DRAW_GRID_OF_SQUARES(SDL_Renderer* renderer, int squareCount, int gridLength, int windowCenterX, int windowCenterY);

void DRAW_RANDOM_LINES(SDL_Renderer* renderer, int numOfLines, int screenWidth, int screenHeight, int maxThickness);

//void DRAW_FILLED_RECT(SDL_Renderer* renderer, int startX, int startY, int endX, int endY);

// End of Header Guard
#endif