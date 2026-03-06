#include "utils.h"
#include "SDL.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cmath>

void SET_CENTER_OF_DISPLAY(int windowWidth, int windowHeight, int* screenWidth, int* screenHeight) {
	SDL_DisplayMode display{};
	SDL_GetCurrentDisplayMode(0, &display);

	int centerX = (display.w / 2) - (windowWidth / 2);
	int centerY = (display.h / 2) - (windowHeight / 2);

	*screenWidth = centerX;
	*screenHeight = centerY;
}

void DRAW_TRIANGLE(SDL_Renderer* renderer, int triangleSideLength, int windowCenterX, int windowCenterY) {
    int trianglePoints[3][2] = {
        { windowCenterX, windowCenterY - (triangleSideLength / 2)},
        { windowCenterX + (triangleSideLength / 2), windowCenterY + (triangleSideLength / 2) },
        { windowCenterX - (triangleSideLength / 2), windowCenterY + (triangleSideLength / 2) }
    };

    for (int i = 0; i < 3; i++) {
        int next = i + 1;
        if (next > 2) {
            next = 0;
        }
        SDL_RenderDrawLine(renderer, trianglePoints[i][0], trianglePoints[i][1], trianglePoints[next][0], trianglePoints[next][1]);
    }
}

void DRAW_GRID_OF_SQUARES(SDL_Renderer* renderer, int squareCount, int gridLength, int windowCenterX, int windowCenterY) {
    int startX = windowCenterX - (gridLength / 2);
    int startY = windowCenterY - (gridLength / 2);
    int endX = startX + gridLength;
    int endY = startY + gridLength;
    float squareLength = gridLength / static_cast<float>(squareCount);
    float lineX = startX;
    float lineY = startY;

    for (int i = 0; i < squareCount; i++) {
        SDL_RenderDrawLine(renderer, lineX, startY, lineX, endY);
        SDL_RenderDrawLine(renderer, startX, lineY, endX, lineY);
        lineX += squareLength;
        lineY += squareLength;
    }

    SDL_RenderDrawLine(renderer, lineX, startY, lineX, endY);
    SDL_RenderDrawLine(renderer, startX, lineY, endX, lineY);
}

void DRAW_RANDOM_LINES(SDL_Renderer* renderer, int numOfLines, int screenWidth, int screenHeight, int maxThickness) {
    srand(time(0));
    for (int i = 0; i < numOfLines; i++) {
        int startX = std::rand() % screenWidth;
        int startY = std::rand() % screenHeight;

        int endX = std::rand() % screenWidth;
        int endY = std::rand() % screenHeight;

        int thickness = std::rand() % maxThickness;

        //printf("Line %i: (%i, %i) -> (%i, %i)\n", i, startX, startY, endX, endY);

        SDL_SetRenderDrawColor(renderer, std::rand() % 255, std::rand() % 255, std::rand() % 255, 255);
        
        for (int i = 0 - thickness / 2; i < thickness / 2; i++) {
            SDL_RenderDrawLine(renderer, startX, startY+i, endX, endY+i);
        }

    }
}

void DRAW_FILLED_RECT(SDL_Renderer* renderer, int startX, int startY, int endX, int endY, int color[3], int borderThickness, int borderColor[3]) {
	for (int y = startY - (borderThickness + 1); y < startY; y++) {
		SDL_SetRenderDrawColor(renderer, borderColor[0], borderColor[1], borderColor[2], 255);
		SDL_RenderDrawLine(renderer, startX - (borderThickness + 1), y, endX + borderThickness, y);
	}
    for (int y = startY; y < endY; y++) {
		SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
        SDL_RenderDrawLine(renderer, startX, y, endX, y);
    }
    for (int y = endY; y <= endY + borderThickness; y++) {
        SDL_SetRenderDrawColor(renderer, borderColor[0], borderColor[1], borderColor[2], 255);
        SDL_RenderDrawLine(renderer, startX - (borderThickness + 1), y, endX + borderThickness, y);
    }
	for (int x = startX - (borderThickness + 1); x < startX; x++) {
		SDL_SetRenderDrawColor(renderer, borderColor[0], borderColor[1], borderColor[2], 255);
		SDL_RenderDrawLine(renderer, x, startY, x, endY);
	}
	for (int x = endX; x <= endX + borderThickness; x++) {
		SDL_SetRenderDrawColor(renderer, borderColor[0], borderColor[1], borderColor[2], 255);
		SDL_RenderDrawLine(renderer, x, startY, x, endY);
	}
}

void DRAW_GRADIENT_GRID(SDL_Renderer* renderer, int squareCount, int gridLength, int color[3], int windowCenterX, int windowCenterY)
{
    int startX = windowCenterX - (gridLength / 2);
    int startY = windowCenterY - (gridLength / 2);
    float squareLength = gridLength / static_cast<float>(squareCount * 2 - 1);
    int squareStartX = startX;
    int squareStartY = startY;

    for (int gridY = 0; gridY < squareCount; gridY++) {
		for (int gridX = 0; gridX < squareCount; gridX++) {
            for (int line = startY; line < startY + squareLength; line++) {
                int startLine = startX;
                int endLine = startLine + squareLength;
                SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
                SDL_RenderDrawLine(renderer, startLine, line, endLine, line);
            }
            startX += (squareLength * 2);
		}
        
        startY += (squareLength * 2);
    }
}