// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_example/example.h"
#include "../lib_list/list.h"
#include <iostream>

void main() {
	Clist newdata;
	newdata.push_front(5);
	newdata.push_back(6);
	newdata.push_front(4);
	newdata.printAll();
	std::cout << "\n";
	newdata.pop_back ();
	newdata.printAll();
	std::cout << "\n";
	

}
