#include "square.h"
#include "SDL.h"

Square::Square() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square constructed with Param(%p)", this);
}

Square::~Square() {}

void Square::Init(int px, int py, int pw, int ph) {
	rect.x = px;
	rect.y = py;
	rect.w = pw;
	rect.h = ph;

	R = 255;
	G = 0;
	B = 0;
}

void Square::Update() {

}

void Square::Input(int pressedKey) {

}

void Square::Render(SDL_Renderer* renderer) {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square rendered with Param(%p)", this);
	SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	SDL_RenderFillRect(renderer, &rect);
}