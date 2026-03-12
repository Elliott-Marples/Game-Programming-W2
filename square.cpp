// Related Header
#include "square.h"

// Project Headers
#include "world.h"



// Constructor
Square::Square() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square Constructed with Param(%p)", this);
}

// Destructor
Square::~Square() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square Destroyed with Param(%p)", this);
}

// Initialisation
void Square::Init(int posX, int posY, int width, int height) {
	// Square Dimensions
	rect.x = posX;
	rect.y = posY;
	rect.w = width;
	rect.h = height;

	// Square Color
	R = 255;
	G = 0;
	B = 0;
	A = 255;
}

// Update
void Square::Update() {

}

// Input
void Square::Input(int pressedKey) {
	switch (pressedKey) {
		case 'w': {
			printf("W was pressed");
			break;
		}
	}
}

// Render
void Square::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, R, G, B, A);
	SDL_RenderFillRect(renderer, &rect);
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Rendering(%p)", this);
}