#pragma once

#include "../lib_QueueFromList/QueueFromList.h"
#include <iostream>
#include <ostream>

using namespace std;

template <class Type>
class PriorityQueue : public Queue 
{
  CNode <pair <Type, int>> data;
  size_t = size;
  
  PriorityQueueQueue{
    size = 0;
  }

  void print() ::Queue;
  bool isEmpty() ::Queue;
};