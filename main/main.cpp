// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_list/list.h"
#include "HashTable.h"
#include <iostream>
#include <tree.h>

void main() {
	MathTree MT;
	MT.Push("23-1/");
	std::cout << MT.Calculate();
}
