#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<direct.h>
#include"GlobalDate.h"


using namespace std;

class Report
{
	string name;
	map<string, double> report;
	string type;
	 double total;
	
public:
	Report(const string name_);
	void DayReport(Date date);
	void MonthReport(Date date);
	void YearReport(Date date);
	void PeriodReport(Date start, Date finish);
	void SetCategoryReport(vector<string> catRep);
	void showReport();
	~Report();
};