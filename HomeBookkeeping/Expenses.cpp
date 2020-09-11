#include "Expenses.h"

Expenses::Expenses(const string _name, const string _category)
{
	name = _name;
	category = _category;
	cost = 0.0;
	ifstream exp(category+"Total.txt", ios::in|ios::_Nocreate);
	if (!exp.is_open()) {
		total = 0.0;
	}
	else exp>>total;
	exp.close();
}

void Expenses::addCost(const double _cost)
{
	cost = _cost;
	fstream exp(category+".txt", ios::out | ios::app);
	exp<<name<<" "<<cost<<endl;
	exp.close();	
	total += _cost;
	exp.open(category+"Total.txt", ios::out);
	exp << total;
	exp.close();
}


void Expenses::delCost(int n)
{
	vector<string>vec;
	string str;
	fstream inout(category + ".txt", ios::in);
	while (!inout.eof()) {
		getline(inout, str);
		vec.push_back(str);
	}
	inout.close();
	inout.open(category + ".txt", ios::out);
	for (size_t i = 0; i < vec.size(); i++)
	{
		if ((n != i + 1)) inout << vec[i]<<endl;
		else continue;
	}
	inout.close();
}

Expenses::~Expenses(){}
