#include "ClientCode.h"

using namespace std;

vector<string>NameMenu = { "Учёт расходов","Учёт доходов","Вывести отчет","Выход" };
vector<COORD> MenuCoord = { {54,13},{54,15},{54,17},{54,19},{54,21},{54,23},{54,25} };
vector<string>ExpCatMenu = { "Продукты","Промтовары","Транспорт","Аптеки","Комунальные","Прочие","Назад" };
vector<string>RepCatExp = { "Продукты","Промтовары","Транспорт","Аптеки","Комунальные","Прочие" };
vector<string>RepCatInc = { "Зарплата","Прочие" };
vector<string>IncCatMenu = { "Зарплата","Прочие","Назад" };
vector<string>RepCatMenu = { "Расходы","Доходы","Назад" };
vector<string>ReportMenu = { "Отчет за день","Месячный отчет","Годовой отчет","Отчет за период","Назад" };
vector<string>AccOperation = { "Добавить","Удалить","Отобразить","Назад" };

int ClientCode()
{
	Bookkeeping Home;
	Home.setCoordMenu(MenuCoord);
	Home.settingReport(RepCatExp, EXPENSES);
	Home.settingReport(RepCatInc, INCOME);

	while (true)
	{
		Home.setItemMenu(NameMenu);
		switch (Home.choiceMenu())
		{
		case AccountingExpenses:
		{
			Home.choiceOperationExp(ExpCatMenu, AccOperation);
			break;
		}
		case AccountingIncome:
		{
			Home.choiceOperationInc(IncCatMenu, AccOperation);
			break;
		}
		case OutputReport:
		{
			Home.choiceReport(RepCatMenu, ReportMenu);
			break;
		}
		case Exit:return 0;

		}
	}
}
