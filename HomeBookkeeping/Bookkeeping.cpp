#include "Bookkeeping.h"

Bookkeeping::Bookkeeping()
{
	protExp = new PrototypeExpenses();
	protInc = new PrototypeIncome();
	protRep = new PrototypeReport();
	editor = new Editor();
	menu = new Menu("Домашняя Бухгалтерия");
	expCat = Products;
	incCat = Salary;
	IRep = DayRep;
	date.day = 0;
	date.month = 0;
	date.year = 0;
}

int Bookkeeping::choiceMenu()
{
	return menu->StartMenu();
}

void Bookkeeping::choiceOperationExp (vector<string>CatNameMenu, vector<string> OperateMenu)
{
	while (true)
	{
		menu->setItemMenu(OperateMenu);
		switch (menu->StartMenu())
		{
		case ADD: 
		{
			EnterExpenses(CatNameMenu);
			break;
		}
			
		case Delete: deleteData("Расходы"); break;
		case Show: ShowData("Расходы"); break;
		case Back: return;
		}
	}
	
}

void Bookkeeping::choiceOperationInc(vector<string> CatNameMenu, vector<string> OperateMenu)
{
	while (true)
	{
		menu->setItemMenu(OperateMenu);
		switch (menu->StartMenu())
		{
		case ADD:
		{
			EnterIncome(CatNameMenu);
			break;
		}

		case Delete: deleteData("Доходы"); break;
		case Show: ShowData("Доходы"); break;
		case Back: return;
		}
	}
}


void Bookkeeping::choiceReport(vector<string> TypeRepMenu, vector<string> CatRepMenu)
{
	
	menu->setItemMenu(TypeRepMenu);
	switch (menu->StartMenu())
	{
	case EXPENSES:
	{
		ShowReport(CatRepMenu, EXPENSES);
		break;
	}

	case INCOME: ShowReport(CatRepMenu, INCOME);
	case BackRep: return;
	}
}

void Bookkeeping::EnterExpenses(vector<string> CatNameMenu)
{
	menu->setItemMenu(CatNameMenu);
	date = menu->EnterDate();
	if (!date.day || !date.month || !date.year)return;
	Accounting* Expenses;
	while (true)
	{
		switch (menu->StartMenu())
		{
		case Products: expCat = Products; break;
		case Industrial: expCat = Industrial; break;
		case Transport: expCat = Transport; break;
		case Farmacy: expCat = Farmacy; break;
		case Utilitys: expCat = Utilitys; break;
		case OtherExp: expCat = OtherExp; break;
		case ExitExp: return;
		}
		string type;
		double cost = 0;
		menu->setData(type, cost);
		cost *= -1;
		Expenses = protExp->CloneExp(expCat);
		Expenses->setDate(date);
		Expenses->writeData(type, cost);
		system("cls");
		Expenses->show();
		cout << "\n\n \"Enter\" - Продолжить" << setw(10) << "\"Esc\" - Назад";
		int button = 0;
		while (button != Enter)
		{
			button = _getch();
			switch (button)
			{
			case Esc:return;
			case Enter:break;
			}
		}
	}
}

void Bookkeeping::EnterIncome(vector<string> CatNameMenu)
{
	menu->setItemMenu(CatNameMenu);
	date = menu->EnterDate();
	if (!date.day || !date.month || !date.year)return;
	Accounting* Income;
	while (true)
	{
		switch (menu->StartMenu())
		{
		case Salary: incCat = Salary; break;
		case OtherInc: incCat = OtherInc; break;
		case ExitInc: return;
		}
		string type;
		double cost = 0;
		menu->setData(type, cost);
		Income = protInc->CloneInc(incCat);
		Income ->setDate(date);
		Income->writeData(type, cost);
		system("cls");
		Income->show();
		cout << "\n\n \"Enter\" - Продолжить" << setw(10) << "\"Esc\" - Назад";
		int button = 0;
		while (button != Enter)
		{
			button = _getch();
			switch (button)
			{
			case Esc:return;
			case Enter:break;
			}
		}
	}
}


void Bookkeeping::deleteData(string name_)
{
	date = menu->EnterDate();
	if (!date.day || !date.month || !date.year)return;
	editor->delData(date,name_);
	int button = 0;
	cout << "\n\n\"Enter\" - Продолжить";
	while (button != Enter)
	{
		button = _getch();
	}

}

void Bookkeeping::ShowData(string name_)
{
	date = menu->EnterDate();
	if (!date.day || !date.month || !date.year)return;
	editor->ShowData(date, name_);
	int button = 0;
	cout << "\n\n\"Enter\" - Продолжить";
	while (button != Enter)
	{
		button = _getch();
	}
}

void Bookkeeping::ShowReport(vector<string> ReportMenu,CatReport CatRep)
{
	menu->setItemMenu(ReportMenu);

		Report report = protRep->Clone(CatRep);
		
		switch (menu->StartMenu())
		{
		case DayRep: 
		{
			date = menu->EnterDate();
			cout << "\n Дневной отчет за " << date.day << '/';
			cout << date.month << '/' << date.year << ":\n";
			if (!date.day || !date.month || !date.year)
			{
				return;
			}
			report.DayReport(date);
			report.showReport();
			break;
		}
		case MonthRep:
		{
			cout << "\n Месячный отчет за ";
			cout << date.month << '/' << date.year << ":\n";
			date = menu->EnterMonth();
			if (!date.month || !date.year) 
			{
				return;
			}
			report.MonthReport(date);
			report.showReport();
			break;
		}
		case YearRep: 
		{
			date = menu->EnterYear();
			if (!date.year) 
			{
				return;
			}
			cout << "\n Годовой отчет за " << date.year << " год:\n";
			report.YearReport(date);
			report.showReport();
			break;
		}
		case PeriodRep:
		{
			Date Start{ 0,0 };
			Date Finish{ 0,0 };
			Start = menu->EnterDate();
			if (!Start.day || !Start.month || !Start.year) 
			{
				return;
			}
			cout << "\n Отчет за период с " << Start.day << '/';
			cout << Start.month << '/' << Start.year << "по ";
			cout << Finish.day << '/' << Finish.month << '/' << Finish.year << ":\n";
			Finish = menu->EnterDate();
			if (!Finish.day || !Finish.month || !Finish.year) 
			{
				return;
			}
			report.PeriodReport(Start, Finish);
			report.showReport();
			break;
		}
		case ExitRep: return;
		}
		cout << "\n\n \"Enter\" - Продолжить";
		switch (_getch())
		{
		case Enter:break;
		}
}

void Bookkeeping::setCoordMenu(vector<COORD> coord)
{
	menu->setCoord(coord);
}

void Bookkeeping::setItemMenu(vector<string> ItemMenu)
{
	menu->setItemMenu(ItemMenu);
}

void Bookkeeping::settingReport(vector<string> CatForRep, CatReport CatRep)
{
	protRep->setCatReport(CatRep, CatForRep);
}

