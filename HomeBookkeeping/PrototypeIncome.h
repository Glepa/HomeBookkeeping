#pragma once
#include<map>
#include"Accounting.h"
#include"GlobalDate.h"


using std::map;
enum IncomeCategory { Salary, OtherInc, ExitInc };

class PrototypeIncome 
{
	map<IncomeCategory, Accounting*> IncProt;
public:
	PrototypeIncome();
	Accounting* CloneInc(IncomeCategory IncCat);
};