// Battleships.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Map.h"

using namespace std;

int main() {

	Map map;

	cout  << endl << map.toString() << endl;
	cout << "\t---------------------" << endl;
	cout << map.toString() << endl << endl;

    return 0;
}

