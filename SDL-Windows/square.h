#ifndef SquareFile
#define SquareFile

#include <iostream>
#include "SDL.h"

class Square {
public:
	Square();
	~Square();

	void Init(int px, int py, int pw, int ph);
	void Update();
	void Input(int pressedKey);

	void Render(SDL_Renderer* renderer);
	SDL_Rect rect;
	int x, y, height, width, R, G, B;

	static int counterTotal;
	int counter;
};

#endif // !SQUARE
