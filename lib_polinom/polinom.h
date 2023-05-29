#pragma once
#include<math.h>
#include <string>
#include <iostream>
#include "../lib_list/list.h"

class monom
{
protected:
	float coef;
	int degreeX, degreeY, degreeZ;
public:
	monom(float coef1, int degreeX1, int degreeY1, int degreeZ1)
	{
		coef = coef1;
		degreeX = degreeX1;
		degreeY = degreeY1;
		degreeZ = degreeZ1;
	}

	monom()
	{
		coef = 0;
		degreeX = 0;
		degreeY = 0;
		degreeZ = 0;
	}

	bool equaldegrees(monom mon)
	{
		return (this->degreeX == mon.degreeX && this->degreeY == mon.degreeY && this->degreeZ == mon.degreeZ);
	}

	std::string print_monom()
	{
		std::string degX = "";
		std::string degY = "";
		std::string degZ = "";

		if (this->degreeX != 0)
		{
			degX = " x^" + std::to_string(degreeX);
		}
		if (this->degreeY != 0)
		{
			degY = " y^" + std::to_string(degreeY);
		}
		if (this->degreeZ != 0)
		{
			degZ = " z^" + std::to_string(degreeZ);
		}

		std::string res = std::to_string(coef) + degX + degY + degZ;
		return res;

	}

	void clear()
	{
		this->coef = 0;
		this->degreeX = 0;
		this->degreeY = 0;
		this->degreeZ = 0;
	}

	void set_degreeX(int _degreeX)
	{
		degreeX = _degreeX;
	}

	void set_degreeY(int _degreeY)
	{
		degreeY = _degreeY;
	}

	void set_degreeZ(int _degreeZ)
	{
		degreeZ = _degreeZ;
	}

	void set_coef(float _coef)
	{
		coef = _coef;
	}

	monom derivative_mon_X()
	{
		monom res = *this;

		res.coef = this->coef * this->degreeX;

		res.degreeX = this->degreeX - 1;

		return res;
	}

	monom derivative_mon_Y()
	{
		monom res = *this;

		res.coef = this->coef * this->degreeY;

		res.degreeY = this->degreeY - 1;

		return res;
	}

	monom derivative_mon_Z()
	{
		monom res = *this;

		res.coef = this->coef * this->degreeZ;

		res.degreeZ = this->degreeZ - 1;

		return res;
	}

	float CalculatePointMonom(int x, int y, int z)
	{
		float result = 0;

		result = this->coef * pow(x, this->degreeX) * pow(y, this->degreeY) * pow(z, this->degreeZ);

		return result;
	};

	monom& operator+(const monom& right)
	{
		monom m;

		m.coef = this->coef + right.coef;
		m.degreeX = this->degreeX;
		m.degreeY = this->degreeY;
		m.degreeZ = this->degreeZ;

		return m;

	};
	monom& operator-(const monom& right)
	{
		monom m;

		m.coef = this->coef - right.coef;
		m.degreeX = this->degreeX;
		m.degreeY = this->degreeY;
		m.degreeZ = this->degreeZ;

		return m;
	};
	monom& operator*(const monom& right)
	{
		monom m;

		m.coef = this->coef * right.coef;
		m.degreeX = this->degreeX + right.degreeX;
		m.degreeY = this->degreeY + right.degreeY;
		m.degreeZ = this->degreeZ + right.degreeZ;

		return m;
	};
	monom& operator*(const int right)
	{
		monom m;

		m.coef = this->coef * right;
		m.degreeX = this->degreeX;
		m.degreeY = this->degreeY;
		m.degreeZ = this->degreeZ;


		return m;
	};
	monom& operator=(const monom& right)
	{
		this->coef = right.coef;
		this->degreeX = right.degreeX;
		this->degreeY = right.degreeY;
		this->degreeZ = right.degreeZ;

		return *this;
	};

	bool operator==(const monom& right1)
	{
		monom right = right1;
		return(this->coef == right.coef
			&& this->degreeX == right.degreeX
			&& this->degreeY == right.degreeY
			&& this->degreeZ == right.degreeZ);
	}

	bool operator!=(const monom& right1) {
		monom right = right1;
		return !(*this == right);
	}

	friend class polinom;

	~monom() {

	}
};


class polinom
{
protected:
	Clist<monom> Lmons;

public:
	polinom()
	{

	}

	polinom(const polinom& other) {
		this->Lmons = other.Lmons;
	}
	polinom(std::string _pol)
	{
		monom m;

		int k = 0;
		if (_pol[0] != '-')
		{
			m.coef = (int)(_pol[0] - 48);
		}
		else
		{
			m.coef = (int)(_pol[1] - 48);
			k = 1;
		}


		for (int i = k; i < _pol.size(); i++)
		{
			if (_pol[i] == 'x' && _pol[i + 1] == '^')
			{
				m.degreeX = (int)(_pol[i + 2] - 48);
				i = i + 2;
			}
			else
			{
				if (_pol[i] == 'y' && _pol[i + 1] == '^')
				{
					m.degreeY = (int)(_pol[i + 2] - 48);
					i = i + 2;
				}
				else
				{
					if (_pol[i] == 'z' && _pol[i + 1] == '^')
					{
						m.degreeZ = (int)(_pol[i + 2] - 48);
						i = i + 2;
					}
					else
					{
						if (_pol[i] == '-' || _pol[i] == '+')
						{
							add_monom(m);
							m.clear();
							m.coef = (int)(_pol[i + 2] - 48);
						}
					}
				}
			}

		}
		add_monom(m);
	}


	//polinom(std::string _pol)
	//{
	//	monom m;
	//	std::string buffer;
	//	int k = 0;
	//	if (_pol[0] != '-')
	//	{
	//		m.coef = (int)(_pol[0] - 48);
	//	}
	//	else
	//	{
	//		m.coef = (int)(_pol[1] - 48);
	//		k = 1;
	//	}
	//	
	//	for (int i = k; i < _pol.size(); i++)
	//	{
	//		if (_pol[i] == 'x' && _pol[i + 1] == '^')
	//		{
	//			buffer = _pol[i + 2];
	//			if ((int)_pol[i + 3] < 48 || (int)_pol[i + 3] > 58)
	//			{
	//				buffer += _pol[i + 3];
	//				i = i + 3;
	//			} else i = i + 2;
	//			m.degreeX = std::stoi(buffer);
	//		}
	//		else
	//		{
	//			if (_pol[i] == 'y' && _pol[i + 1] == '^')
	//			{
	//				buffer = _pol[i + 2];
	//				if ((int)_pol[i + 3] < 48 || (int)_pol[i + 3] > 58)
	//				{
	//					buffer += _pol[i + 3];
	//					i = i + 3;
	//				}
	//				else i = i + 2;
	//				m.degreeY = std::stoi(buffer);
	//			}
	//			else
	//			{
	//				if (_pol[i] == 'z' && _pol[i + 1] == '^')
	//				{
	//					buffer = _pol[i + 2];
	//					if ((int)_pol[i + 3] < 48 || (int)_pol[i + 3] > 58)
	//					{
	//						buffer += _pol[i + 3];
	//						i = i + 3;
	//					}
	//					else i = i + 2;
	//					m.degreeZ = std::stoi(buffer);
	//				}
	//				else
	//				{
	//					if (_pol[i] == '-' || _pol[i] == '+')
	//					{
	//						add_monom(m);
	//						m.clear();
	//						m.coef = (int)(_pol[i + 2] - 48);
	//					}
	//				}
	//			}
	//		}
	//	}
	//	add_monom(m);
	//}

	float CalculatePointPolinom(int x, int y, int z)
	{
		float result = 0;

		for (int i = 0; i < Lmons.size(); i++)
		{
			result += Lmons.GetIndEl(i).CalculatePointMonom(x, y, z);
		}

		return result;
	};

	void add_monom(monom m)
	{
		this->Lmons.push_back(m);
	}

	polinom derivative(int mode)
	{

		polinom pol = *this;

		switch (mode)
		{

		case 1:
		{

			polinom res;

			for (size_t i = 0; i < this->Lmons.size(); i++)
			{
				if (pol.Lmons.GetIndEl(i).degreeX == 0)
				{
					throw std::logic_error("Degree X = 0!");
				}

				res.Lmons.push_back(pol.Lmons.GetIndEl(i).derivative_mon_X());
			}

			return res;
			break;
		}

		case 2:
		{
			polinom res;

			for (size_t i = 0; i < this->Lmons.size(); i++)
			{
				if (pol.Lmons.GetIndEl(i).degreeY == 0)
				{
					throw std::logic_error("Degree Y = 0!");
				}

				res.Lmons.push_back(pol.Lmons.GetIndEl(i).derivative_mon_Y());
			}

			return res;
			break;
		}

		case 3:
		{
			polinom res;

			for (size_t i = 0; i < this->Lmons.size(); i++)
			{
				if (pol.Lmons.GetIndEl(i).degreeZ == 0)
				{
					throw std::logic_error("Degree Z = 0!");
				}

				res.Lmons.push_back(pol.Lmons.GetIndEl(i).derivative_mon_Z());
			}

			return res;
			break;
		}
		default:
		{
			throw std::logic_error("Invalid data!");
		}
		break;
		}
	}

	polinom& operator=(const polinom& right) {
		this->Lmons = right.Lmons;

		return *this;
	}

	polinom& operator+(const polinom& right)
	{
		polinom rig = right;
		polinom res;

		for (int i = 0; i < rig.Lmons.size(); i++)
		{
			bool flag = false;
			for (int j = 0; j < this->Lmons.size(); j++)
			{
				if (this->Lmons.GetIndEl(j).equaldegrees(rig.Lmons.GetIndEl(i)))
				{
					res.Lmons.push_back(this->Lmons.GetIndEl(j) + rig.Lmons.GetIndEl(i));
					flag = true;
				}
			}
			if (!flag)
			{
				res.Lmons.push_back(rig.Lmons.GetIndEl(i));
			}
		}

		return res;
	};

	polinom& operator-(const polinom& right)
	{
		polinom rig = right;
		polinom res;

		for (int i = 0; i < rig.Lmons.size(); i++)
		{
			bool flag = false;
			for (int j = 0; j < this->Lmons.size(); j++)
			{
				if (this->Lmons.GetIndEl(j).equaldegrees(rig.Lmons.GetIndEl(i)))
				{
					res.Lmons.push_back(this->Lmons.GetIndEl(j) - rig.Lmons.GetIndEl(i));
					flag = true;
				}
			}
			if (!flag)
			{
				rig.Lmons.GetIndEl(i).set_coef(rig.Lmons.GetIndEl(i).coef * -1);
				res.Lmons.push_back(rig.Lmons.GetIndEl(i));
			}
		}

		return res;
	};
	polinom& operator*(const int right)
	{
		polinom _res;

		for (int i = 0; i < this->Lmons.size(); i++)
		{
			_res.Lmons.push_back(this->Lmons.GetIndEl(i) * right);
		}

		return _res;
	};
	polinom& operator*(const polinom& right)
	{
		monom res;
		polinom _res;
		polinom pol = right;

		for (int i = 0; i < this->Lmons.size(); i++)
		{
			for (int j = 0; j < pol.Lmons.size(); j++)
			{
				_res.Lmons.push_back(this->Lmons.GetIndEl(i) * pol.Lmons.GetIndEl(j));
			}
		}
		return _res;
	};

	bool operator==(const polinom& right) {
		polinom pol = right;
		if (this->Lmons.size() != pol.Lmons.size()) return false;
		for (int i = 0; i < this->Lmons.size(); i++) {
			if (this->Lmons.GetIndEl(i) != pol.Lmons.GetIndEl(i)) return false;
		}
		return true;
	}

	int CountMonoms() {
		return Lmons.size();
	}

	std::string print_polinom()
	{

		std::string res = this->Lmons.GetIndEl(0).print_monom();
		for (int i = 1; i < this->Lmons.size(); i++)
		{
			if (this->Lmons.GetIndEl(i).coef > 1)
			{
				res += " + ";
			}
			else
			{
				res += " - ";
			}
			res += this->Lmons.GetIndEl(i).print_monom();
		}

		return res;
	}

	void PrintMenu() {
		std::cout << "\n---------------------------------------------------\n";
		std::cout << "\n\t\tМЕНЮ ВЗАИМОДЕЙСТВИЙ\n";
		std::cout << "\n\t1) Вычислить значение полнома";
		std::cout << "\n\t2) Сумма полиномов";
		std::cout << "\n\t3) Разность полиномов";
		std::cout << "\n\t4) Произведение полиномов";
		std::cout << "\n\t5) Произведение полинома на число";
		std::cout << "\n\t6) Конец";
		std::cout << "\n\n---------------------------------------------------\n";
		std::cout << "\n>Введите циферку: ";
	}

	void Menu() {
		int mode = 0;
		while (mode != 6) {
			PrintMenu();
			std::cin >> mode;
			switch (mode)
			{
			case 1: {
				std::string polstr;
				int x, y, z;
				std::cout << "\n>Введите полином:\n";
				std::cin >> polstr;
				polinom  p1(polstr);
				std::cout << "\n>Введите Аргументы\n";
				std::cout << "\nХ:\n";
				std::cin >> x;
				std::cout << "\nY:\n";
				std::cin >> y;
				std::cout << "\nZ:\n";
				std::cin >> z;
				std::cout << "\n--------------------\n";
				std::cout << "\n\tРезультат: " << p1.CalculatePointPolinom(x, y, z) << "\n";
				std::cout << "\n--------------------\n";
				break;
			}
			case 2: {
				std::string polstr;
				std::cout << "\n>Введите первый полином:\n";
				std::cin >> polstr;
				polinom  p1(polstr);
				std::cout << "\n>Введите второй полином:\n";
				std::cin >> polstr;
				polinom  p2(polstr);
				std::cout << "\n--------------------\n";
				std::cout << "\n\tРезультат: " << (p1 + p2).print_polinom() << "\n";
				std::cout << "\n--------------------\n";
				break;
			}
			case 3: {
				std::string polstr;
				std::cout << "\n>Введите первый полином:\n";
				std::cin >> polstr;
				polinom  p1(polstr);
				std::cout << "\n>Введите второй полином:\n";
				std::cin >> polstr;
				polinom  p2(polstr);
				std::cout << "\n--------------------\n";
				std::cout << "\n\tРезультат: " << (p1 - p2).print_polinom() << "\n";
				std::cout << "\n--------------------\n";
				break;
			}
			case 4: {
				std::string polstr;
				std::cout << "\n>Введите первый полином:\n";
				std::cin >> polstr;
				polinom  p1(polstr);
				std::cout << "\n>Введите второй полином:\n";
				std::cin >> polstr;
				polinom  p2(polstr);
				std::cout << "\n--------------------\n";
				std::cout << "\n\tРезультат: " << (p1 * p2).print_polinom() << "\n";
				std::cout << "\n--------------------\n";
				break;
			}
			case 5: {
				std::string polstr;
				int num;
				std::cout << "\n>Введите первый полином:\n";
				std::cin >> polstr;
				polinom  p1(polstr);
				std::cout << "\n>Введите второй множитель:\n";
				std::cin >> num;
				std::cout << "\n--------------------\n";
				std::cout << "\n\tРезультат: " << (p1 * num).print_polinom() << "\n";
				std::cout << "\n--------------------\n";
				break;
			}
			case 6: {
				std::cout << "\n------------------------------------------------------\n";
				std::cout << "\n\t СПАСИБО ЗА ИСПОЛЬЗОВАНИЕ ПРОГРАМОЙ!\n";
				std::cout << "\n\t\tХОРОШЕГО ДНЯ!\n";
				break;
			}
			default:
				std::cout << "\n>Не не не, другую циферку\n";
				break;
			}


		}
	}

	bool IsEmpty() {
		return(Lmons.size() == 0);
	}

	~polinom() {
		Lmons.clear();
	}

};

