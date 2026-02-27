// SDL-Windows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include "SDL.h"
#include "SDL_render.h"
#include "utils.h"

// Main Function with SDL required parameters
int main(int argc, char *argv[])
{
    // Initialise, if this fails, exit program
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return 1;
    }

    // Screen Dimensions
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    // Screen Positions
    int screenX{};
    int screenY{};

    // Set positions to center window
    SET_CENTER_OF_DISPLAY(SCREEN_WIDTH, SCREEN_HEIGHT, &screenX, &screenY);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Elliott Marples: 29183333", screenX, screenY, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    // Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set background to sky blue
    SDL_SetRenderDrawColor(renderer, 255, 140, 150, 255);
    SDL_RenderClear(renderer);

    // Define Window Center
    int windowCenterX = SCREEN_WIDTH / 2;
    int windowCenterY = SCREEN_HEIGHT / 2;
    
    // Add triangle in center
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    DRAW_TRIANGLE(renderer, 256, windowCenterX, windowCenterY);

    // Add purple diagonal line across screen
    SDL_SetRenderDrawColor(renderer, 160, 42, 240, 255);
    SDL_RenderDrawLine(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Draw a grid of 100 blue squares
    SDL_SetRenderDrawColor(renderer, 150, 200, 255, 255);
    DRAW_GRID_OF_SQUARES(renderer, 10, 256, windowCenterX, windowCenterY);

    // Draw random lines of various lengths & colours
    DRAW_RANDOM_LINES(renderer, 10, SCREEN_WIDTH, SCREEN_HEIGHT, 20);

    //// Draw filled rectangle
    //SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
    //DRAW_FILLED_RECT(renderer, 100, 100, 200, 150);

    // Draw to screen
    SDL_RenderPresent(renderer);

    // Wait 4 secs before continuing program
    SDL_Delay(4000);

    // Exit
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
