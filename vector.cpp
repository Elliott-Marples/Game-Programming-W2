// Related Header
#include "vector.h"

// Standard Headers
#include <cmath>


Vector::Vector() {

}

Vector::Vector(int x, int y) {
	this->x = x;
	this->y = y;
}

float Vector::Magnitude() {
	return sqrt(pow(static_cast<float>(x), 2.0f) + pow(static_cast<float>(y), 2.0f));
}