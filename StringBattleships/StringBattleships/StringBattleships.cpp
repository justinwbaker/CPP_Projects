// StringBattleships.cpp : Defines the entry point for the console application.
// author: justin baker
// inputs: coordinates, directions to make guesses and place ships
// outputs: game area and if can place ship or not and if hit or missed enemy ship

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

const int AmountToDeath = 17;//5 + 4 + 3 + 3 + 2;
char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

using namespace std;

enum Direction {
	North, South, East, West, InvalidDirection
};

char player_map[10][10];
char player_guesses[10][10];
char enemy_map[10][10];

void initMaps() {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			player_map[x][y] = '~';
			enemy_map[x][y] = '~';
			player_guesses[x][y] = '~';
		}
	}
}

void printMap(char map[10][10]) {
	cout << "\t\t|# 0 1 2 3 4 5 6 7 8 9 |" << endl;
	for (int y = 0; y < 10; y++) {
		cout << "\t\t|" << alphabet[y] << " ";
		for (int x = 0; x < 10; x++) {
			cout << "" << map[x][y] << " ";
		}
		cout << "|" << endl;
	}
}

void renderScreen() {
	system("CLS");
	cout << "\t\tJustin's Battleships v01" << endl << endl;
	cout << "\t\t,----------------------," << endl;
	printMap(player_guesses);
	cout << "\t\t|----------------------|" << endl;
	printMap(player_map);
	cout << "\t\t'----------------------'" << endl;
}

bool placeShip(int x, int y, Direction direction, int length, char (&map)[10][10], bool print = false) {
	switch (direction)
	{
	case North:
		if (y - length >= 0 && y < 10 && x >= 0 && x < 10) {
			for (int i = 0; i < length; i++) {
				if (map[x][y - i] != '~') {
					if(print) cout << "Can't place over ship" << endl;
					return false;
				}
			}
			for (int i = 0; i < length; i++) {
				map[x][y - i] = '^';
			}
			return true;
		}
		else {
			if (print)cout << "Not In Bounds" << endl;
			return false;
		}
		break;
	case South:
		if (y + length < 10 && y >= 0 && x >= 0 && x < 10) {
			for (int i = 0; i < length; i++) {
				if (map[x][y + i] != '~') {
					if (print)cout << "Can't place over ship" << endl;
					return false;
				}
			}
			for (int i = 0; i < length; i++) {
				map[x][y + i] = '^';
			}
			return true;
		}
		else {
			if (print)cout << "Not In Bounds" << endl;
			return false;
		}
		break;
	case West:
		if (x - length >= 0 && x < 10 && y >= 0 && y < 10) {
			for (int i = 0; i < length; i++) {
				if (map[x - i][y] != '~') {
					if (print)cout << "Can't place over ship" << endl;
					return false;
				}
			}
			for (int i = 0; i < length; i++) {
				map[x - i][y] = '^';
			}
			return true;
		}
		else {
			if (print)cout << "Not In Bounds" << endl;
			return false;
		}
		break;
	case East:
		if (x + length < 10 && x >= 0 && y >= 0 && y < 10) {
			for (int i = 0; i < length; i++) {
				if (map[x + i][y] != '~') {
					if (print)cout << "Can't place over ship" << endl;
					return false;
				}
			}
			for (int i = 0; i < length; i++) {
				map[x + i][y] = '^';
			}
			return true;
		}
		else {
			if (print)cout << "Not In Bounds" << endl;
			return false;
		}
		break;
	default:
		return false;
		break;
	}
}

void shoot(int x, int y) {
	if (player_map[x][y] == '^') {
		player_map[x][y] = '*';
	}
	else {
		player_map[x][y] = '-';
	}
}

void shootEnemy(int x, int y) {
	if (enemy_map[x][y] == '^') {
		enemy_map[x][y] = '*';
		player_guesses[x][y] = '*';
	}
	else if (enemy_map[x][y] == '~') {
		enemy_map[x][y] = '/';
		player_guesses[x][y] = '/';
	}
	else if (enemy_map[x][y] == '*') {

	}
}

void shootPlayer(int x, int y) {
	if (player_map[x][y] == '^') {
		player_map[x][y] = '*';
	}
	else if (player_map[x][y] == '~') {
		player_map[x][y] = '/';
	}
	else if (player_map[x][y] == '*') {

	}
}

bool isDead(char(&map)[10][10]) {
	int counter = 0;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (map[x][y] == '*') {
				counter++;
			}
		}
	}
	if (counter >= AmountToDeath) {
		return true;
	}
	else {
		return false;
	}
}

void stringToCoord(string coords, int &x, int &y) {

	if (coords.empty()) {
		x = -1;
		y = -1;
		return;
	}

	if (isalpha(coords[0])) {
		coords[0] = tolower(coords[0]);
		switch (coords[0]) {
		case 'a':
			y = 0;
			break;
		case 'b':
			y = 1;
			break;
		case 'c':
			y = 2;
			break;
		case 'd':
			y = 3;
			break;
		case 'e':
			y = 4;
			break;
		case 'f':
			y = 5;
			break;
		case 'g':
			y = 6;
			break;
		case 'h':
			y = 7;
			break;
		case 'i':
			y = 8;
			break;
		case 'j':
			y = 9;
			break;
		default:
			y = -1;
			break;
		}
	}
	coords = coords.substr(1, 1);
	if (isdigit(coords[0])) {
		x = stoi(coords);
	}
	else {
		x = -1;
	}
}

Direction stringToDirection(string direction) {

	if (direction.empty()) {
		return InvalidDirection;
	}

	for (int i = 0; i < direction.length(); i++) {
		direction[i] = tolower(direction[i]);
	}

	if (direction.find("north") != string::npos) {
		return North;
	}
	else if (direction.find("south") != string::npos) {
		return South;
	}
	else if (direction.find("east") != string::npos) {
		return East;
	}
	else if (direction.find("west") != string::npos) {
		return West;
	}
	else {
		return InvalidDirection;
	}
}

void makeGuess() {
	string answer = "";
	int x = -1, y = -1;
	cout << "Enter your guess in coordinates A-J0-9" << endl;
	getline(cin, answer);
	stringToCoord(answer, x, y);

	while (x == -1 || y == -1 || player_guesses[x][y] != '~') {
			cout << "Invalid Coordinates Please Enter Again..." << endl;
			getline(cin, answer);
			stringToCoord(answer, x, y);
	}

	shootEnemy(x, y);
}

int getRandomCoord() {
	return rand() % 10;
}

void enemyGuess() {
	int x = getRandomCoord();
	int y = getRandomCoord();

	while (player_map[x][y] == '/' || player_map[x][y] == '*') {
		x = getRandomCoord();
		y = getRandomCoord();
	}

	shootPlayer(x, y);
}

Direction getRandomDirection() {
	int dir = rand() % 4;

	switch (dir)
	{
	case 0:
		return North;
		break;
	case 1:
		return South;
		break;
	case 2:
		return East;
		break;
	case 3:
		return West;
		break;
	default:
		break;
	}

}

int main()
{
	srand(time(NULL));
	initMaps();
	string coords = "";
	string direction = "";
	Direction enemyDirection = InvalidDirection;
	int x = 0, y = 0;

	renderScreen();

	for (int i = 0; i < 5; i++) {
		int length = 0;
		string ship = "";
		switch (i) {
		case 0:
			ship = "Aircraft Carier";
			length = 5;
			break;
		case 1:
			ship = "Battleship";
			length = 4;
			break;
		case 2:
			ship = "Submarine";
			length = 3;
			break;
		case 3:
			ship = "Cruiser";
			length = 3;
			break;
		case 4:
			ship = "Destroyer";
			length = 2;
			break;
		}

		while (!placeShip(x, y, stringToDirection(direction), length, player_map, true)) {
			cout << "Where would you like to place your " << ship << "?(A-J0-9 Direction)" << endl;
			cin >> coords >> direction;

			stringToCoord(coords, x, y);

			while (x == -1 || y == -1) {
				cout << "Please enter valid coordinates (A-J0-9)?" << endl;
				cin >> coords;
				stringToCoord(coords, x, y);
			}

			while (stringToDirection(direction) == InvalidDirection) {
				cout << "Please enter valid direction (north, south, east, west)?" << endl;
				cin >> direction;
			}
		}
		renderScreen();

		coords = "";
		direction = "";
		x = 0;
		y = 0;
	}

	//AI placement
	for (int i = 0; i < 5; i++) {
		int length = 0;
		switch (i) {
		case 0:
			length = 5;
			break;
		case 1:
			length = 4;
			break;
		case 2:
			length = 3;
			break;
		case 3:
			length = 3;
			break;
		case 4:
			length = 2;
			break;
		}

		while (!placeShip(x, y, enemyDirection, length, enemy_map)) {
			x = getRandomCoord();
			y = getRandomCoord();
			enemyDirection = getRandomDirection();
		}

		coords = "";
		direction = "";
		x = 0;
		y = 0;
	}

	cin.ignore();

	while (!isDead(player_map) && !isDead(enemy_map)) {
		makeGuess();
		enemyGuess();
		renderScreen();
	}

	if (isDead(player_map)) {
		cout << "You Lose!!!!!!!!" << endl;
	}

	if (isDead(enemy_map)) {
		cout << "You Win!!!!!!!!" << endl;
	}

    return 0;
}

