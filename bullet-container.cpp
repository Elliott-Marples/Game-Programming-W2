// Related Header
#include "bullet-container.h"

void BulletContainer::Add(int x, int y) {
	Bullet* bullet = new Bullet();
	bullet->Init(x, y);
	this->bullets.push_back(bullet);
}

void BulletContainer::Init(int x, int y, int cap, int lifespan) {
	this->x = x;
	this->y = y;
	this->cap = cap;

	body.x = this->x;
	body.y = this->y;
	body.w = 20;
	body.h = 20;

	for (int i = 0; i < cap; i++) {
		int posX = this->x;
		int posY = this->y;
		Add(posX, posY);
	}

	this->lifespan = lifespan;
}

void BulletContainer::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &body);

	for (auto& bullet : bullets) {
		if (bullet->velocity.x != 0) {
			bullet->Render(renderer);
		}
	}
}

void BulletContainer::Update(Bounds bounds) {
	for (auto& bullet : bullets) {
		bullet->Update();

		if (bullet->velocity.x > 0) {
			bullet->lifeCount++;
		}
		else {
			bullet->x = this->x;
			bullet->y = this->y;
		}

		if (bullet->lifeCount > lifespan) {
			// Continue from slides
		}
	}
}