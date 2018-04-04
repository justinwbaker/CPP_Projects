#include <string>
#include "Ship.h"

const char ALPHABET[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

using namespace std;

class Map {
private:
	char charMap[100];

public:
	Map();
	void addShip(Ship ship);
	string toString();
};