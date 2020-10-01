#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<direct.h>
#include"GlobalDate.h"

using namespace std;

class Editor
{
	string Category;
	string type;
	double cost;
public:
	Editor();
	void ShowData(Date date, string name);
	void delData(Date date, string name);
};