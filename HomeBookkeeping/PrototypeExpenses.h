#pragma once
#include<map>
#include"Accounting.h"
#include"GlobalDate.h"


using std::map;
enum ExpensesCategory {
	Products, Industrial, Transport, Farmacy,
	Utilitys, OtherExp, ExitExp
};

class PrototypeExpenses 
{
	map<ExpensesCategory, Accounting*> ExProt;
public:
	PrototypeExpenses();
	Accounting* CloneExp(ExpensesCategory ExpCat);
};