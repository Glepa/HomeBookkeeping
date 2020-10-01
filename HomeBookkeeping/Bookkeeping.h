#pragma once
#include"GlobalDate.h"
#include"Editor.h"
#include"Menu.h"
#include"PrototypeExpenses.h"
#include"PrototypeIncome.h"
#include"PrototypeReport.h"
#include"Report.h" 

using namespace std;
enum ITEM_MENU { AccountingExpenses, AccountingIncome, OutputReport, Exit };
enum Operation { ADD, Delete,Show, Back };
enum ItemReport{DayRep,MonthRep,YearRep,PeriodRep,ExitRep};

class Bookkeeping
{
	PrototypeExpenses* protExp;
	PrototypeIncome* protInc;
	PrototypeReport* protRep;
	Editor* editor;
	Menu* menu;
	ExpensesCategory expCat;
	IncomeCategory incCat;
	ItemReport IRep;
	Date date;
public:
	Bookkeeping();
	int choiceMenu();
	void choiceOperationExp(vector<string>CatNameMenu, vector<string> OperateMenu);
	void choiceOperationInc(vector<string>CatNameMenu, vector<string> OperateMenu);
	void choiceReport(vector<string>TypeRepMenu, vector<string> CatRepMenu);
	void EnterExpenses(vector<string>CatNameMenu);
	void EnterIncome(vector<string>CatNameMenu);
	void deleteData(string name_);
	void ShowData(string name_);
	void ShowReport(vector<string>ReportMenu, CatReport CatRep);
	void setCoordMenu(vector<COORD> coord);
	void setItemMenu(vector<string>ItemMenu);
	void settingReport(vector<string>CatForRep, CatReport CatRep);
};