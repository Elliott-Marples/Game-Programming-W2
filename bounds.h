#ifndef GAME_BOUNDS_H_
#define GAME_BOUNDS_H_

class Bounds {
public:
	Bounds();
	Bounds(int x, int y);

	int left, top, right, bottom;
};

#endif // !GAME_BOUNDS_H_
