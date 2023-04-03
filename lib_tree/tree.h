#pragma once
#include <iostream>

template <class Type>
class Cnode {
	Type data;
	Cnode<Type>* Left;
	Cnode<Type>* Right;

public:


	Cnode(Type data1) {
		data = data1;
		Left = nullptr;
		Right = nullptr;
	}
	Cnode() {
		Left = nullptr;
		Right = nullptr;
	}

	void SetData(Type data1) {
		data = data1;
	}

	void SetLeft(Cnode<Type>* newNode) {
		Left = newNode;
	}

	void SetRight(Cnode<Type>* newNode) {
		Right = newNode;
	}

	Type GetData() {
		return data;
	}

	Cnode<Type>* GetLeft() { return Left; }
	Cnode<Type>* GetRight() { return Right; }

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
			while (Copy->GetLeft() != NewNode && Copy->GetRight() != NewNode) {
				if (Copy->GetData() < NewNode->GetData())
				{
					if (Copy->GetLeft() == nullptr) Copy->SetLeft(NewNode);
					else Copy = Copy->GetLeft();
				}
				else {
					if (Copy->GetRight() == nullptr) Copy->SetRight(NewNode);
					else Copy = Copy->GetRight();
				}
			}
		}
	}

	Cnode<Type>* Find(Type findData) {
		Cnode <Type>* Copy = root;
		bool flag = true;
		while (flag)
		{
			if (Copy->GetData() == findData) return Copy;
			if (Copy->GetData() < findData)
			{
				if (Copy->GetLeft() == nullptr) flag = false;
				else Copy = Copy->GetLeft();
			}
			else {
				if (Copy->GetRight() == nullptr) flag = false;
				else Copy = Copy->GetRight();
			}
		}
		if (Copy->GetData() == findData) return Copy;
		return nullptr;
	}

	void DelElement(Type element) override
	{
		bool flag = false;
		Cnode <Type>* Copy = root;
		Cnode <Type>* DelNode = root;
		while (DelNode->GetData() != element )
		{
			if (Copy->GetLeft()->GetData() == element) DelNode = Copy->GetLeft();
			else if (Copy->GetRight()->GetData() == element) DelNode = Copy->GetRight();
				else {
					if (Copy->GetData() < element) Copy = Copy->GetLeft();
					else Copy = Copy->GetRight();
				}
		}
		if (DelNode != root)
		{
			if (Copy->GetLeft() == DelNode)
			{
				if (DelNode->GetRight() != nullptr) Copy->SetLeft(DelNode->GetRight());
				else if (DelNode->GetLeft() != nullptr) Copy->SetLeft(DelNode->GetLeft());
				else
				{
					flag = true;
					Copy->SetLeft(nullptr);
				}
			}
			else {
				if (DelNode->GetRight() != nullptr) Copy->SetRight(DelNode->GetRight());
				else if (DelNode->GetLeft() != nullptr) Copy->SetRight(DelNode->GetLeft());
				else
				{
					flag = true;
					Copy->SetRight(nullptr);
				}
			}
		}
		else if (DelNode->GetRight() != nullptr) {
			root = DelNode->GetRight();
			DelNode = DelNode->GetLeft();
		}
		else if (DelNode->GetLeft() != nullptr)
		{
			root = DelNode->GetRight();
			DelNode = DelNode->GetLeft();
		}
		else {
			root = nullptr;
			flag = true;
		}
		
		if (!flag)
		{
			Copy = root;
			while (Copy->GetLeft() != DelNode && Copy->GetRight() != DelNode) {
				if (Copy->GetData() < DelNode->GetData())
				{
					if (Copy->GetLeft() == nullptr) Copy->SetLeft(DelNode);
					else Copy = Copy->GetLeft();
				}
				else {
					if (Copy->GetRight() == nullptr) Copy->SetRight(DelNode);
					else Copy = Copy->GetRight();
				}
			}
		}
	}
};



template <class Type>
class MathTree : public Tree <Type>
{
	Cnode<char>* root;
public:
	MathTree(std::string expression) {

	}

	void DelElement(Type element) override {

	}

	void Push(Type newElement) override {

	}

	float Calculate() {
		float res;

		return result;
	}
};

