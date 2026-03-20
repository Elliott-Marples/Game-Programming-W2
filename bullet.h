// Define Guard
#ifndef GAME_BULLET_H_
#define GAME_BULLET_H_

// Standard Headers
#include <iostream>

// Library Headers
#include "SDL.h"

// Project Headers
#include "vector.h"



// Declarations
class Bullet {
public:
	Bullet(); // Constructor
	~Bullet(); // Destructor

	// Bullet Methods
	void Init(int posX, int posY);
	void Update();
	void Input(int key, bool isPressed);
	void Render(SDL_Renderer* renderer);

	int x, y;
	bool moving;
	int lifeCount;

	Vector velocity;

private:
	SDL_Rect body;
};



#endif // !GAME_SQUARE_H_
