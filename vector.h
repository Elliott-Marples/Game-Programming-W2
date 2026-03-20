#ifndef GAME_VECTOR_H_
#define GAME_VECTOR_H_

class Vector {
public:
	Vector();
	Vector(int x, int y);
	int x, y;
	float Magnitude();
};

#endif // !GAME_VECTOR_H_
