#pragma once
#include <map>
#include"Report.h"

using std::map;
enum CatReport {EXPENSES,INCOME,BackRep};

class PrototypeReport
{
	map<CatReport, Report*>prototypeReport;
public:
	PrototypeReport();
	void setCatReport(CatReport CatRep, vector<string>CatForRep);
	Report Clone(CatReport CatRep);
};