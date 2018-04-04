#include "stdafx.h"
#include "Ship.h"

Ship::Ship(ShipType type, int length, Direction direction, int x, int y)
{
	this->type = type;
	this->length = length;
	this->direction = direction;
	this->x = x;
	this->y = y;
	for (int i = 0; i < this->length; i++) {
		this->sunk[i] = false;
	}
}

bool Ship::isSunk() {
	int numbSunk = 0;
	for (int i = 0; i < this->length; i++) {
		if (this->sunk[i]) {
			numbSunk++;
		}
	}
	if (numbSunk == length) {
		return true;
	}
	else {
		return false;
	}
}