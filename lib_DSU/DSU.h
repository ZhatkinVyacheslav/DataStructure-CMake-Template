#include <iostream>
#include <ostream>
#include "../lib_list/list.h"
#include <math.h>
#include <vector>

class Element
{
	int data;
	Element* rep;
	Element* next;
	friend class DSU;
	friend class MazeDSU;
public:
	Element(){
		data = NULL;
		rep = this;
		next = nullptr;
	}

	Element(int data1) {
		data = data1;
		rep = this;
		next = nullptr;
	}

	void print() {
		std::cout << data << " ->";
	}

	Element* BaseFunk() {
		return this;
	}

	Element operator=(Element* right) {
		data = right->data;
		rep = right->rep;
		next = right->next;

		return *this;
	}
};


class DSU{

private:
	Element* sets;
	int* rank;
	int size;
	friend class MazeDSU;

public:
	DSU(std::vector<std::pair<int, int>> VecEnemies , int size1) {
		sets = new Element[size1];
		rank = new int[size1];
		size = size1;
		int sizeSets = 2;
		int* MainSets = new int[size]; 
		for (int i = 0; i < size; i++) {
			sets[i] = new Element(i);
			rank[i] = 1;
		}

		for (int j = 0; j < size; j++) MainSets[j] = NULL;
		MainSets[0] = VecEnemies[0].first;
		MainSets[1] = VecEnemies[0].second;
		for (int i = 0; i < VecEnemies.size(); i++) {
			bool flag = true;

			if (find(VecEnemies[i].first) == find(VecEnemies[i].second)) {
				ununit(find(VecEnemies[i].second), VecEnemies[i].second);

				for (int j = 2; j < sizeSets; j++) {
					if (find(VecEnemies[i].first) != MainSets[j]) {
						unite(MainSets[j], VecEnemies[i].second);
						flag = false;
					}
				}
				if (flag) {
					MainSets[sizeSets] = VecEnemies[i].second;
					sizeSets++;
					flag = false;
				}
				return;
			}

			for (int j = 0; j < sizeSets; j++) {
				if (find(VecEnemies[i].first) == MainSets[j]) flag = false;
			}

			if (flag) {
				for (int j = 0; j < sizeSets; j++) {
					if (find(VecEnemies[i].second) != MainSets[j]) {
						unite(MainSets[j], VecEnemies[i].first);
						flag = false;
						j = sizeSets;
					}
				}
			}
			
			flag = true;

			for (int j = 0; j < sizeSets; j++) {
				if (find(VecEnemies[i].second) == MainSets[j]) flag = false;
			}

			if (flag) {
				for (int j = 0; j < sizeSets; j++) {
					if (find(VecEnemies[i].first) != MainSets[j]) {
						unite(MainSets[j], VecEnemies[i].second);
						flag = false;
						j = sizeSets;
					}
				}
			}
		}
	}

	DSU(int size1) {
		sets = new Element[size1];
		rank = new int[size1];
		size = size1;
		for (int i = 0; i < size; i++) {
			sets[i] = new Element(i);
			rank[i] = 1;
		}
	}

	int find(int elem) {
		
		return sets[elem].rep->data;
		
		//return NULL;
	}

	void unite(int elem1, int elem2) {
		Element* cur = sets[elem1].rep;
		for (int j = 1; j < rank[elem1]; j++) {
			cur = cur->next;
		}
		sets[elem2].rep = sets[elem1].rep;
		cur->next = sets[elem2].rep;
		cur = cur->next;
		for (int j = 0; j < rank[elem2]; j++)
		{
			cur->rep = sets[elem1].rep;
			cur = cur->next;
		}
		rank[elem1] += rank[elem2];
		rank[elem2] = 0;
	}

	void ununit(int pos, int el) {
		Element* cur = sets[pos].BaseFunk();

		if (pos == el) throw std::logic_error("tak nel'zya");
		while (cur->next->data != el) {
			cur = cur->next;
		}
		rank[cur->next->data] = 1;
		cur->next->rep = cur->next;
		cur->next = cur->next->next;
		rank[pos]--;
	}

	void print() {
		for (int i = 0; i < size; i++)
		{
			if (rank[i] > 0) {
				Element* cur = sets[i].rep;
				for (int j = 0; j < rank[i]; j++) {
					std::cout << cur->data << "-> ";
					cur = cur->next;
				}
				std::cout << "\n";
			}
		}
	}
	
	DSU operator=(DSU* right) {
		for (int i = 0; i < size; i++) {
			sets[i] = right->sets[i];
			rank[i] = right->rank[i];
		}
	 }

	~DSU() {
		delete[] sets;
		delete[] rank;
	}

};

class MazeDSU {
	DSU dsu;
	std::string** wall;
	int WallSize;
	int size;
public:
	MazeDSU(int size1) : dsu(size1) {
		size = size1;
		WallSize = sqrt(size1) * 2 - 1;
		wall = new std::string * [WallSize];
		for (int i = 0; i < WallSize; i++) {
			wall[i] = new std::string[WallSize];
		}
		contour();
	}

	void print() {
		for (int i = 0; i < WallSize; i++) {
			std::cout << "\n";
			for (int j = 0; j < WallSize; j++) {
				std::cout << wall[i][j];
 			}
		}
	}

	void UpdateDSU(DSU newDSU) {
		dsu = newDSU;
		CreateWalls();
	}

	void AddWall(int elem1, int elem2) {
		if (elem1 < 0 || elem2 < 0 || elem1 > size || elem2 > size) throw std::logic_error("Ne pravilnoe chislo");

		if (dsu.find(elem1) != dsu.find(elem2)) dsu.unite(elem1, elem2);
		int y, x, XYsize = sqrt(size);

		if (elem1 - elem2 == 1) {
			y = elem1 / XYsize * 2;
			x = elem1 % XYsize * 2 - 1;
			wall[y][x] = "---";
		}
		else if (elem2 - elem1 == 1) {
			y = elem1 / XYsize * 2;
			x = elem2 % XYsize * 2 - 1;
			wall[y][x] = "---";
		}
		else if (elem1 - XYsize == elem2) {
			y = elem1 / XYsize * 2 - 1;
			x = elem1 % XYsize * 2;
			wall[y][x] = " | ";
		}
		else if (elem1 + XYsize == elem2) {
			y = elem2 / XYsize * 2 - 1;
			x = elem1 % XYsize * 2;
			wall[y][x] = " | ";
		}
	}

	void CreateWalls() {
		for (int i = 0; i < size; i++) {
			if (dsu.rank[i] != 1) {
				Element* cur = dsu.sets[i].rep;
				while (cur != nullptr) {
					AddWall(dsu.sets[i].data, cur->data);
				}
			}
		}
	}

private:
	void contour() {
		for (int i = 0; i < WallSize; i++) {
			for (int j = 0; j < WallSize; j++) {
				if (i % 2 == 0 && j % 2 == 0) wall[i][j] = " o ";
				else if ((i == 0 || i == WallSize - 1) && j % 2 != 0) wall[i][j] = "---";
				else if ((j == 0 || j == WallSize - 1) && i % 2 != 0) wall[i][j] = " | ";
				else wall[i][j] = "   ";
				wall[0][1] = "   ";
				wall[WallSize - 1][WallSize - 2] = "   ";
			}
		}
	}

};
