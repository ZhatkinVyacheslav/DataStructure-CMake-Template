#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../lib_StackFromList/StackFromList.h"

template <class Type>
class Tree;
template <class Type>
class FindTree;

template <class Type>
class Cnode {
	Type data;
	Cnode<Type>* Left;
	Cnode<Type>* Right;

public:

	friend class FindTree<Type>;

	Cnode(Type data1) {
		data = data1;
		Left = nullptr;
		Right = nullptr;
	}
	Cnode() {
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



template <class Type>
class MathTree : public Tree <Type>
{
private:
	Cnode<char>* root;

	void postorder(Node* root1) {
		if (root == nullptr) {
			return;
		}

		postorder(root1->left);
		postorder(root1->right);
		cout << root1->data;
	}

	void inorder(Node * root1) {
		if (root1 == nullptr) {
			return;
		}

		if (isOperator(root1->data)) {
			cout << "(";
		}

		inorder(root1->left);
		cout << root1->data;
		inorder(root1->right);

		if (isOperator(root1->data)) {
			cout << ")";
		}
	}

public:
	MathTree() {
		root = nullptr;
	}

	void Push(string postfix) {

		if (postfix.length() == 0) {
			return nullptr;
		}

		StackFromList<Cnode<char>*> s;

		for (char c : postfix)
		{
			if (isOperator(c)) {
				Cnode<char>* x = s.top();
				s.Pop();
				Cnode<char>* y = s.top();
				s.Pop();
				Cnode<char>* node = new Cnode<char>*(c, y, x);
				s.Push(node);
			} else s.Push(new Cnode<char>*(c));
		}
		root = s.Top();
	}

	bool isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
	}

	void PostPrint() {
		postorder(root);
	}

	void InfPrint() {
		inorder(root);
	}

	char Calculate(Cnode<char>* root1) {
		int res;
		if (isOperator(root1->Left->data)) {
			Cnode<char>* NewLeftNode = new Cnode<char>*(Calculate(root1->Left));
			root1->Left = NewLeftNode;
		}
		if (isOperator(root1->Right->data)) {
			Cnode<char>* NewRightNode = new Cnode<char>*(Calculate(root1->Right));
			root1->Right = NewRightNode;
		}

		switch (root1->data)
		{
		case '+': {
			res = atoi(root1->Left->data) + atoi(root1->Right->data);
			break;
		}
		case '-': {
			res = atoi(root1->Left->data) - atoi(root1->Right->data);
			break;
		}
		case '*': {
			res = atoi(root1->Left->data) * atoi(root1->Right->data);
			break;
		}
		case '/': {
			res = atoi(root1->Left->data) / atoi(root1->Right->data);
			break;
		}
			default:
				break;
		}

		char result = (char)(((int)'0') + res);
		return result;
	}
};

