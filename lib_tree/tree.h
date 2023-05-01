#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../lib_StackFromList/StackFromList.h"

template <class Type>
class Tree;
template <class Type>
class FindTree;
class MathTree;

template <class Type>
class Cnode {
	Type data;
	Cnode<Type>* Left;
	Cnode<Type>* Right;

public:

	friend class FindTree<Type>;
	friend class MathTree;

	Cnode(Type data1) {
		data = data1;
		Left = nullptr;
		Right = nullptr;
	}
	Cnode() {
		data = NULL;
		Left = nullptr;
		Right = nullptr;
	}

	Cnode(Type data1, Cnode<Type>* Left1, Cnode<Type>* Right1)
	{
		data = data1;
		Left = Left1;
		Right = Right1; 
	}

	Cnode operator=(const Cnode<Type> right) {
		this->data = right.data;
		this->Left = right.Left;
		this->Right = right.Right;
	}

	bool operator==(const Cnode<Type> &CN1) {
		return (CN1.data == this->data &&
			CN1.Left == this->Left &&
			CN1.Right == this->Right);
	}

	bool operator !=(const Cnode &right1) {
		return !(this == right1);
	}
};


template <class Type>
class Tree
{
	Cnode<Type>* root;

public:
	Tree() {
		root = nullptr;
	}

	Tree(Type root1) {
		Cnode<Type> newroot(root1);
		root = newroot;
	}

	virtual void Push(Type newElement) = 0;
	virtual void DelElement(Type element) = 0;
};

template <class Type>
class FindTree : public Tree <Type> 
{
	Cnode<Type>* root;
public:
	FindTree() {
		root = nullptr;
	}

	FindTree(Type root1) {
		Cnode<Type> newroot(root1);
		root = newroot;
	}

	void Push(Type newElement) override
	{
		Cnode<Type>* NewNode = new Cnode<Type>(newElement);
		if (root == NULL) root = NewNode;
		else {
			Cnode <Type>* Copy = root;
			while (Copy->Left != NewNode && Copy->Right != NewNode) {
				if (Copy->data < NewNode->data)
				{
					if (Copy->Left == nullptr) Copy->Left = NewNode;
					else Copy = Copy->Left;
				}
				else {
					if (Copy->Right == nullptr) Copy->Right = NewNode;
					else Copy = Copy->Right;
				}
			}
		}
	}

	Cnode<Type>* Find(Type findData) {
		Cnode <Type>* Copy = root;
		bool flag = true;
		while (flag)
		{
			if (Copy->data == findData) return Copy;
			if (Copy->data < findData)
			{
				if (Copy->Left == nullptr) flag = false;
				else Copy = Copy->Left;
			}
			else {
				if (Copy->Right == nullptr) flag = false;
				else Copy = Copy->Right;
			}
		}
		if (Copy->data == findData) return Copy;
		return nullptr;
	}

	void DelElement(Type element) override
	{
		bool flag = false;
		Cnode <Type>* Copy = root;
		Cnode <Type>* DelNode = root;
		while (DelNode->data != element )
		{
			if (Copy->Left->data == element) DelNode = Copy->Left;
			else if (Copy->Right->data == element) DelNode = Copy->Right;
				else {
					if (Copy->data < element) Copy = Copy->Left;
					else Copy = Copy->Right;
				}
		}
		if (DelNode != root)
		{
			if (Copy->Left == DelNode)
			{
				if (DelNode->Right != nullptr) Copy->Left = DelNode->Right;
				else if (DelNode->Left != nullptr) Copy->Left = DelNode->Left;
				else
				{
					flag = true;
					Copy->Left = nullptr;
				}
			}
			else {
				if (DelNode->Right != nullptr) Copy->Right = DelNode->Right;
				else if (DelNode->Left != nullptr) Copy->Right = DelNode->Left;
				else
				{
					flag = true;
					Copy->Right = nullptr;
				}
			}
		}
		else if (DelNode->Right != nullptr) {
			root = DelNode->Right;
			DelNode = DelNode->Left;
		}
		else if (DelNode->Left != nullptr)
		{
			root = DelNode->Right;
			DelNode = DelNode->Left;
		}
		else {
			root = nullptr;
			flag = true;
		}
		
		if (!flag)
		{
			Copy = root;
			while (Copy->Left != DelNode && Copy->Right != DelNode) {
				if (Copy->data < DelNode->data)
				{
					if (Copy->Left == nullptr) Copy->Left = DelNode;
					else Copy = Copy->Left;
				}
				else {
					if (Copy->Right == nullptr) Copy->Right = DelNode;
					else Copy = Copy->Right;
				}
			}
		}
	}

	void print() {
		/*PrintTree(root, 1);*/
		PrintTree(root);
	}

private:
	void PrintTree(Cnode<Type>* curr) {
		if (curr) // Проверка на ненулевой указатель
		{
			PrintTree(curr->Left);
			cout << curr->data << " ";
			PrintTree(curr->Right);
		}
		/*if (curr != nullptr)
		{
			if (lenghtEl(curr->data) == level) cout << curr->data << " ";
			else if (lenghtEl(curr->data) < level) {
				PrintTree(curr->Left, level);
				PrintTree(curr->Right, level);
			}
		}
		level++;
		cout << "\n";
		PrintTree(root, level);*/
	}


	int lenghtEl(Type findData) {
		Cnode <Type>* Copy = root;
		int res = 1;
		bool flag = true;
		while (flag)
		{
			if (Copy->data == findData) return res;
			if (Copy->data < findData)
			{
				if (Copy->Left == nullptr) flag = false;
				else
				{
					Copy = Copy->Left;
					res++;
				}
			}
			else {
				if (Copy->Right == nullptr) flag = false;
				else
				{
					Copy = Copy->Right;
					res++;
				}
			}
		}
		if (Copy->data == findData) return res;
		return 0;
	}
};


class CharCnode {
	char data;
	CharCnode* Left;
	CharCnode* Right;

public:
	friend class MathTree;

	CharCnode(char data1) {
		data = data1;
		Left = nullptr;
		Right = nullptr;
	}
	CharCnode() {
		data = '0';
		Left = nullptr;
		Right = nullptr;
	}

	CharCnode(char data1, CharCnode* Left1, CharCnode* Right1)
	{
		data = data1;
		Left = Left1;
		Right = Right1;
	}

	void SetData(char data1) {
		data = data1;
	}

};

class MathTree /*: public Tree <char>*/
{
private:
	CharCnode* root;

	bool isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
	}

	void postorder(CharCnode* root1) {
		if (root == nullptr) {
			return;
		}

		postorder(root1->Left);
		postorder(root1->Right);
		std::cout << root1->data;
	}

	void inorder(CharCnode* root1) {
		if (root1 == nullptr) {
			return;
		}

		if (isOperator(root1->data)) {
			std::cout << "(";
		}

		inorder(root1->Left);
		std::cout << root1->data;
		inorder(root1->Right);

		if (isOperator(root1->data)) {
			std::cout << ")";
		}
	}
	int Calculate(CharCnode* root1) {
		int res;
		if (isOperator(root1->Left->data)) {
			CharCnode* NewLeftNode = new CharCnode();
			NewLeftNode->data = Calculate(root1->Left);
			root1->Left = NewLeftNode;
		}
		if (isOperator(root1->Right->data)) {
			CharCnode* NewRightNode = new CharCnode();
			NewRightNode->data = Calculate(root1->Right);
			root1->Right = NewRightNode;
		}

		switch (root1->data)
		{
		case '+': {
			res = (int)(root1->Left->data - 48) + (int)(root1->Right->data - 48);
			break;
		}
		case '-': {
			res = (int)(root1->Left->data - 48) - (int)(root1->Right->data - 48);
			break;
		}
		case '*': {
			res = (int)(root1->Left->data - 48) * (int)(root1->Right->data - 48);
			break;
		}
		case '/': {
			res = (int)(root1->Left->data - 48) / (int)(root1->Right->data - 48);
			break;
		}
		default:
			break;
		}

		char result = (char)(((int)'0') + res);
		return result;
	}
	
public:
	MathTree() {
		root = nullptr;
	}

	void Push(std::string postfix) {

		if (postfix.length() == 0) {
			throw std::logic_error("pusto");
		}

		StackFromList<CharCnode*> s;

		for (int i = 0; i < postfix.length(); i++)
		{
			if (isOperator(postfix[i])) {
				CharCnode* x = s.Top();
				s.Pop();
				CharCnode* y = s.Top();
				s.Pop();
				CharCnode* node = new CharCnode();
				node->data = postfix[i];
				node->Left = x;
				node->Right = y;
				s.Push(node);
			}
			else
			{
				char c = postfix[i];
				CharCnode* node = new CharCnode();
				node->data = c;
				s.Push(node);
			}
		}
		root = s.Top();
	}

	void PostPrint() {
		postorder(root);
	}

	void InfPrint() {
		inorder(root);
	}

	char Calculate() {
		return Calculate(root);
	}

};

