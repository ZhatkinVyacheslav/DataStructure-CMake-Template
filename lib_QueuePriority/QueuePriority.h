#pragma once

#include "../lib_QueueFromList/QueueFromList.h"
#include <iostream>
#include <ostream>
#include "../lib_list/list.h"

using namespace std;

template <class Type>
class PriorityQueue :public LQueue <Type>
{
protected:
  list <pair <int, Type>> data;
  size_t = size;

public:
  PriorityQueue () {
      size = 0;
  }

  virtual void Push(const Type val) {}

  virtual void Pop() {}

  void Print() {

  }
};

template <class Type>
class PriorityQueueMode1 :public PriorityQueue <Type>
{
public:
    void Push(const pair <int, Type> val) override
    {
        if (isEmpty()) {
            size++;
            data.push_back(val);
        }
        else {
          CNode<Type>* newnode = new CNode<Type>(val);
          cur = head;
          while () {
            if (cur->next.get_data().first >)
            cur = cur->next;
          }

        }
    }

    void Pop() override
    {
        if (!isEmpty()) {
            data.pop_front();
            size--;
        }
        else {
            throw std::logic_error("Error!!! Queue is empty");
        }
    }
};

template <class Type>
class PriorityQueueMode2 : public PriorityQueue <Type>
{
public:
    void Push(const Type val) override 
    {
        size++;
        data.push_back(val);
    }

    void Pop() override
    {
        int biggestpr;
        data

        CNode
    }
};
