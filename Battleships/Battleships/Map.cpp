#include "stdafx.h"
#include <iostream>
#include "Map.h"

Map::Map() {
	for (int i = 0; i < 100; i++) {
		this->charMap[i] = '~';
	}
}

void Map::addShip(Ship ship) {
	switch (ship.direction)
	{
	default:
		break;
	}
}

string Map::toString() {
	string returnString = "";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			returnString += this->charMap[j + i * 10];
			returnString += " ";
		}
		if(i < 9)
			returnString += "\n";
	}
	return returnString;
}