// Battleships.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>

const int AmountToDeath = 5 + 4 + 3 + 3 + 2;
char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

using namespace std;

enum Direction {
	North, South, East, West
};

char player_map[10][10];
char player_guesses[10][10];
char enemy_map[10][10];

string playerName = "Player 1";
string enemyName = "Enemy 1";

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
	cout << "\t#|0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "\t-+-------------------" << endl;
	for (int y = 0; y < 10; y++) {
		cout << "\t" << alphabet[y] << "|";
		for (int x = 0; x < 10; x++) {
			cout << map[x][y] << " ";
		}
		cout << endl;
	}
}

void renderScreen() {
	system("CLS");
	cout << "\tEnemy Name: " << enemyName << endl;
	printMap(player_guesses);
	cout << endl << "\tPlayer Name: " << playerName << endl;
	printMap(player_map);
}

void placeShip(int x, int y, Direction direction, int length, char(&map)[10][10]) {
	switch (direction)
	{
	case North:
		if (y - length > 0 && y < 10 && x >= 0 && x < 10) {
			for (int i = 0; i < length; i++) {
				map[x][y - i] = '^';
			}
		}
		break;
	case South:
		if (y + length < 10 && y > 0 && x >= 0 && x < 10) {
			for (int i = 0; i < length; i++) {
				map[x][y + i] = '^';
			}
		}
		break;
	case East:
		if (x - length > 0 && x < 10 && y >= 0 && y < 10) {
			for (int i = 0; i < length; i++) {
				map[x - i][y] = '^';
			}
		}
		break;
	case West:
		if (x + length < 10 && x > 0 && y >= 0 && y < 10) {
			for (int i = 0; i < length; i++) {
				map[x + i][y] = '^';
			}
		}
		break;
	default:
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
	else {
		enemy_map[x][y] = '-';
		player_guesses[x][y] = '-';
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

bool validCoordinateString(string coordinates) {
	bool isValid = true;
	string string_x = coordinates.substr(1);
	string string_y = coordinates.substr(0, 1);

	if (!stoi(string_x)) {
		isValid = false;
	}

	string alpha(alphabet);
	if (alpha.find(string_y[0]) == string::npos) {
		isValid = false;
	}

	int x = stoi(string_x);
	int y = alpha.find(string_y[0]);

	if (x > 9 || x < 0) {
		isValid = false;
	}

	if (y > 9 || y < 0) {
		isValid = false;
	}

	if (x == 0) {
		isValid = true;
	}

	if (enemy_map[x][y] == '-') {
		isValid = false;
	}
	cout << "X: " << stoi(string_x) << " Y: " << alpha.find(string_y[0]) << endl;
	return isValid;
}

void makeGuess() {
	string answer = "";
	cout << "Enter your guess in coordinates A-J0-9" << endl;
	getline(cin, answer);

	while (!validCoordinateString(answer)) {
		cout << "Invalid Coordinates Please Enter Again..." << endl;
		getline(cin, answer);
	}
	string alpha(alphabet);
	int x = stoi(answer.substr(1));
	int y = alpha.find(answer.substr(0, 1)[0]);

	shootEnemy(x, y);
}

int main()
{

	initMaps();

	for (int i = 0; i < 3; i++) {
		placeShip(i, 5, North, i+2, player_map);
	}

	while (!isDead(enemy_map)) {
		renderScreen();
		makeGuess();
	}

	return 0;
}