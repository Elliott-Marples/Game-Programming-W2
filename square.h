// Define Guard
#ifndef GAME_SQUARE_H_
#define GAME_SQUARE_H_

// Standard Headers
#include <iostream>

// Library Headers
#include "SDL.h"



// Declarations
class World;

class Square {
public:
	Square(); // Constructor
	~Square(); // Destructor

	// Square Methods
	void Init(int posX, int posY, int width, int height);
	void Update();
	void Input(int pressedKey);
	void Render(SDL_Renderer* renderer);

	SDL_Rect rect; // SDL Rectangle Object
	int x, y, height, width, R, G, B, A; // Rectangle Properties

	static int squareCounterTotal;
	int squareCounter;

	World* parent;
};



#endif // !GAME_SQUARE_H_
