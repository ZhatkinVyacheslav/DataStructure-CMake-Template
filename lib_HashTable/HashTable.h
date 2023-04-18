#include <stdio.h>
#include <iostream>

class CNodeForTable {
	int Link;
	std::string Word;

	friend class HashTable;
public:
	CNodeForTable() {
		
	}

	CNodeForTable(int Link1, std::string Word1) {
		Link = Link1;
		Word = Word1;
	}

	bool operator==(const CNodeForTable Right) {
		return (this->Word == Right.Word);
	}

	CNodeForTable operator=(const CNodeForTable Right) {
		this->Link = Right.Link;
		this->Word = Right.Word;
		return *this;
	}
};

class HashTable {
private:
	std::pair<int, CNodeForTable>* data;

	int HashFunction(std::string CodWord) {
		int res = 0;
		for (auto letter : CodWord) {
			res += (int)letter;
		}
		return res % 30;
	}

	int Recalculation(int res) {
		if (res == 30) res = 1;
		if (res > 30) res -= 30;
		return res;
	}

public:
	HashTable() {
		data = new std::pair<int, CNodeForTable>[30];
		for (int i = 0; i < 30; i++) {
			data[i].first = NULL;
		}
	}

	void Insert(int Link1, std::string Word1) {
		if (IsFull()) throw std::logic_error("Beda!! Is Full");
		CNodeForTable NewNode(Link1, Word1);
		bool flag = false;
		int ind = HashFunction(Word1);
		Recalculation(ind);
		
		while (data[ind].first != NULL && !flag)
		{
			if (data->second.Word == NewNode.Word) flag = true;
			else {
				ind += 3;
				Recalculation(ind);
			}
		}
		if (!flag) data[ind].second = NewNode;
	}

	void Print() {
		for (int i = 0; i < 30; i++) {
			if (data[i].first != NULL) std::cout << "\n" << data[i].first << ")" << data[i].second.Word << " - " << data[i].second.Link;
		}
	}

	void Erase(int pos) {
		data[pos].first = NULL;
	}

	bool IsFull() {
		for (int i = 0; i < 30; i++) {
			if (data[i].first == NULL) return false;
		}
		return true;
	}
};