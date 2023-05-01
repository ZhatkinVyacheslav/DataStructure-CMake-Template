#include <iostream>
#include <ostream>
#include "../lib_list/list.h"

class Element
{
	int data;
	Element* rep;
	Element* next;
public:
	Element(){
		rep = nullptr;
		next = nullptr;
	}

	Element(int data1) {
		data = data1;
		rep = nullptr;
		next = nullptr;
	}
	
	void SetData(int newdata) {
		data = newdata;
	}

	void SetNext(Element* next1){
		next = next1;
	}

	void SetRep(Element* rep1) {
		rep = rep1;
	}

	Element* GetNext() {
		return next;
	}

	Element* GetRep() {
		return rep;
	}

	int GetData() {
		return data;
	}

	void print() {
		std::cout << data << " ->";
	}

	Element operator=(Element* right) {
		data = right->data;
		rep = right->rep;
		next = right->next;
	}
};


class DSU
{/*
	Element* MassEl;
	size_t size;
	size_t maxsize;

public: 
	DSU(size_t size1)
	{
		maxsize - size1;
		MassEl = new Element[size1];
		size = 0;
	}

	void MakeSet(int newdata) {
		MassEl[size].SetData(newdata);
		MassEl[size].SetRep(&MassEl[size]);
		size++;
		if (size > maxsize) throw std::logic_error("beda");
	}

	void Unite(int fstInd, int ScndInd) {
		Element* cur = MassEl[fstInd].GetRep();
		while (cur->GetNext() != nullptr) {
			cur = cur->GetNext();
		}
		cur->SetNext(&MassEl[ScndInd]);
		cur = cur->GetNext();
		while (cur->GetNext() != nullptr) {
			cur->SetRep(&MassEl[fstInd]);
			cur = cur->GetNext();
		}
		cur->SetRep(&MassEl[fstInd]);

		for (int i = ScndInd; i < size - 1; i++) {
			MassEl[i] = MassEl[i + 1];
		}
		size--;
	}

	int find(int findnum) {
		for (int i = 0; i < size; i ++ ) {
			Element* cur = &MassEl[i];
			while (cur->GetNext() != nullptr) {
				if (cur->GetData() == findnum) { return cur->GetData(); }
			}
			if (cur->GetData() == findnum) { return cur->GetData(); }
		}
		return 0;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			Element* cur = &MassEl[i];
			while (cur->GetNext() != nullptr) {
				cur->print();
			}
			cur->print();
			std::cout << "\n";
		}
	}*/


private:
	int* data;
	int* rank;
	int size;
public:
	DSU(int size) {
		data = new int[size];
		rank = new int[size];
		size = size;
		for (int i = 0; i < size; i++) {
			data[i] = i;
			rank[i] = 0;
		}
	}

	int get_data(int pos) { return data[pos]; }

	int find(int elem) {
		return elem != data[elem] ? find(data[elem]) : elem;
	}

	void unite(int elem1, int elem2) {
		int pX = find(elem1);
		int pY = find(elem2);
		if (rank[elem1] > rank[elem2]) {
			data[pY] = pX;
		}
		else {
			data[pX] = pY;
			if (rank[elem1] == rank[elem2]) { rank[elem2]++; }
		}
	}

	void print() {
		for (int i = 0; i < size; i++)
		{
			std::cout << '(' << data[i] << ') ';
		}
	}

	~DSU() {
		delete[] data;
		delete[] rank;
	}

};
