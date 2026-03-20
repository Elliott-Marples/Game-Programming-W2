#include "bounds.h"

Bounds::Bounds() {
	this->left = 0;
	this->top = 0;
	this->right = 0;
	this->bottom = 0;
}

Bounds::Bounds(int x, int y) {
	this->left = 0;
	this->top = 0;
	this->right = x;
	this->bottom = y;
}