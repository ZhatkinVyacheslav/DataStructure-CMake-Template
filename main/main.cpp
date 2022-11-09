// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_example/example.h"
#include "../lib_list/list.h"
#include <iostream>

void main() {
	CNode node1(5);
	CNode node2(6);
	node2.set_next(&node1);
	node1.print();
	node2.print();
	std::cout << "\n" << node2.get_next();
}
