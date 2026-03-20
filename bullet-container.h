#ifndef GAME_BULLET_CONTAINER_H_
#define GAME_BULLET_CONTAINER_H_

// Standard Headers
#include <vector>

// Library Headers
#include "SDL.h"

// Project Headers
#include "bullet.h"
#include "bounds.h"

class BulletContainer {
public:
	BulletContainer();
	~BulletContainer();

	void Init(int x, int y, int cap, int lifespan);
	void Add(int x, int y);
	void Input(int key, bool isPressed);
	void Render(SDL_Renderer* renderer);
	void Update(Bounds bounds);

	std::vector<Bullet*> bullets;

	void Shoot();
	int x, y, cap, lifespan;
	SDL_Rect body;
};

#endif // !GAME_BULLET_CONTAINER_H_
