// Battleships.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Map.h"

using namespace std;



int main() {

	Map map;

	cout << map.toString() << endl;
	cout << "-------------------" << endl;
	cout << map.toString() << endl;

    return 0;
}

