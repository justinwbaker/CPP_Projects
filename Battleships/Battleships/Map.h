#include <string>
#include "Ship.h"

using namespace std;

class Map {
private:
	char charMap[100];

public:
	Map();
	void addShip(Ship ship);
	string toString();
};