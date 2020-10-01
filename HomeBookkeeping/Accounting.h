#pragma once
#include<string>
#include<iostream>
#include<direct.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include"GlobalDate.h"
using namespace std;

class Accounting 
{
	Date date;
	string name;
	string category;
	string type;
	double cost;
public:
	Accounting(const string name_, const string category_);
	void setDate(Date date_);
	void writeData(string type_, double cost_);
	void show();
	~Accounting();
};