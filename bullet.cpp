// Related Header
#include "bullet.h"

// Project Headers
#include "world.h"



// Constructor
Bullet::Bullet() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bullet Constructed with Param(%p)", this);
}

// Destructor
Bullet::~Bullet() {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bullet Destroyed with Param(%p)", this);
}

// Initialisation
void Bullet::Init(int posX, int posY) {
	body.x = posX;
	body.y = posY;
	body.w = 20;
	body.h = 5;

	this->x = x;
	this->y = y;

	moving = false;

	lifeCount = 0;

	velocity.x = 0;
	velocity.y = 0;
}

// Input
void Bullet::Input(int key, bool isPressed) {
	switch (key) {
	case SDLK_SPACE:
		if (!moving) {
			moving = true;
		}
		break;
	}
}

// Update
void Bullet::Update() {
	body.x = x;
	body.y = y;

	x += velocity.x;
	y += velocity.y;
}

// Render
void Bullet::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &body);
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Rendering bullet(%p)", this);
}