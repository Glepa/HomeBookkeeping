#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
//#include"Handler.h"


using namespace std;

class Expenses {
	string name;
	string category;
	double cost;
	double total;
public:
	Expenses(const string _name, const string _category);
	void addCost(const double _cost);
	void delCost(int n);
	~Expenses();
};
