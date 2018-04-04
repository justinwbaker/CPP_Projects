#include <vector>

using namespace std;

enum ShipType {
	Destroyer, Cruiser, Submarine, Battleship, Aircraft
};

enum Direction {
	North, South, East, West
};

class Ship {
private:
	ShipType type;
	int length;
	int x, y;
	vector<bool> sunk;

public:
	Direction direction;
	Ship(ShipType type, int length, Direction direction, int x, int y);
	bool isSunk();
};

