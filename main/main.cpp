// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_list/list.h"
#include "HashTable.h"
#include <iostream>
#include <tree.h>
#include <DSU.h>

void main() {
	MazeDSU MD(25);
	MD.AddWall(5, 6);
	MD.AddWall(6, 7);
	MD.AddWall(3, 8);
	MD.AddWall(11, 16);
	MD.AddWall(16, 21);
	MD.AddWall(16, 17);
	MD.AddWall(17, 18);
	MD.AddWall(12, 13);
	MD.AddWall(13, 14);
	MD.print();
}
