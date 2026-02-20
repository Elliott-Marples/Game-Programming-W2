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
    int windowCenter[2] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    
    // Add triangle in center
    int triangleSideLength = 128;

    int trianglePoints[3][2] = {
        { windowCenter[0], windowCenter[1] - (triangleSideLength / 2)},
        { windowCenter[0] + (triangleSideLength / 2), windowCenter[1] + (triangleSideLength / 2) },
        { windowCenter[0] - (triangleSideLength / 2), windowCenter[1] + (triangleSideLength / 2) }
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int i = 0; i < 3; i++) {
        int next = i + 1;
        if (next > 2) {
            next = 0;
        }
        SDL_RenderDrawLine(renderer, trianglePoints[i][0], trianglePoints[i][1], trianglePoints[next][0], trianglePoints[next][1]);
    }

    // Add purple diagonal line across screen
    SDL_SetRenderDrawColor(renderer, 160, 42, 240, 255);
    SDL_RenderDrawLine(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Draw a grid of 100 blue squares
    SDL_SetRenderDrawColor(renderer, 150, 200, 255, 255);

    int gridLength = 256;
    int startX = windowCenter[0] - (gridLength / 2);
    int startY = windowCenter[1] - (gridLength / 2);
    int endX = startX + gridLength;
    int endY = startY + gridLength;
    float squareLength = gridLength / 10;
    float lineX = startX;
    float lineY = startY;

    for (int i = 0; i < 10; i++) {
        SDL_RenderDrawLine(renderer, lineX, startY, lineX, endY);
        lineX += squareLength;
    }
    SDL_RenderDrawLine(renderer, lineX, startY, lineX, endY);

    lineX = startX;
    lineY = startY;

    for (int i = 0; i < 10; i++) {
        SDL_RenderDrawLine(renderer, startX, lineY, endX, lineY);
        lineY += squareLength;
    }
    SDL_RenderDrawLine(renderer, startX, lineY, endX, lineY);

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
