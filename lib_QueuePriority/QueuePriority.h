#pragma once

#include <iostream>
#include <ostream>
#include "../lib_priorityList/priorutyList.h"

using namespace std;

template <class Type>
class PriorityQueue
{
protected:
  PriorityCList<Type> Qdata;
  size_t size;

public:
  PriorityQueue () {
      size = 0;
  }

  void Push(const int pr, const Type val) {
      Qdata.push_back(pr, val);
      size++;
  }

  void Pop() {
      if (isEmpty())
      {
          throw std::logic_error("Empty!");
      }
      Qdata.pop_front();
      size--;
  }
    

  Type Top() {
      if (isEmpty())
      {
          throw std::logic_error("Empty!");
      }
      return Qdata.GetFirstValue();
  }
    
 /* size_t size() {
      return size;
  }*/

  bool isEmpty() {
      if (size == 0) return true;
      else return false;
  }

  void Print() {
      Qdata.print();
  }
};





template <class Type>
class PriorityQueueMode1 : public PriorityQueue <Type>
{

public:
    void Push(const int pr, const Type val) /*override */
    {
        Qdata.push_back_priority(pr, val);
        size++;
    }

};




template <class Type>
class PriorityQueueMode2 : public PriorityQueue <Type>
{

public:

    void Pop() 
    {
        if (isEmpty())
        {
            throw std::logic_error("Empty!");
        }
        Qdata.pop_front_priority();
        size--;
    }

    Type Top()
    {
        if (isEmpty())
        {
            throw std::logic_error("Empty!");
        }
        return Qdata.GetFirstValuePriority();
    }
};
