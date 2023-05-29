// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_list/list.h"
#include "HashTable.h"
#include <iostream>
#include <tree.h>
#include <DSU.h>
#include <vector>
#include<polinom.h>

void main() {
	setlocale(LC_ALL, "Russian");

	/*MazeDSU MD(25);
	MD.AddWall(5, 6);
	MD.AddWall(6, 7);
	MD.AddWall(3, 8);
	MD.AddWall(11, 16);
	MD.AddWall(16, 21);
	MD.AddWall(16, 17);
	MD.AddWall(17, 18);
	MD.AddWall(12, 13);
	MD.AddWall(13, 14);
	MD.print();*/

	//std::vector<std::pair<int, int>> VecEnemies;
	//std::pair<int, int> y1{ 0,1 };
	//VecEnemies.push_back(y1);
	//y1 = { 2, 3 };
	//VecEnemies.push_back(y1);
	//y1 = { 0, 4 };
	//VecEnemies.push_back(y1);
	//y1 = { 3, 5 };
	//VecEnemies.push_back(y1);
	////y1 = { 2, 5 };
	////VecEnemies.push_back(y1);

	//DSU dsu(VecEnemies, 6);
	//dsu.print();

	//std::cout << "\n" << dsu.find(2);
	//std::cout << "\n" << dsu.find(5);

	polinom p;
	p.Menu();
}