#include"Bookkeeping.h"

vector<string>NameMenu = { "���� ��������","���� �������","������� �����","�����" };
vector<COORD> MenuCoord = { {54,13},{54,15},{54,17},{54,19},{54,21},{54,23},{54,25} };
vector<string>ExpCatMenu = { "��������","����������","���������","������","�����������","������","�����" };
vector<string>RepCatExp = { "��������","����������","���������","������","�����������","������" };
vector<string>RepCatInc = { "��������","������" };
vector<string>IncCatMenu = { "��������","������","�����" };
vector<string>RepCatMenu = { "�������","������","�����" };
vector<string>ReportMenu = { "����� �� ����","�������� �����","������� �����","����� �� ������","�����" };
vector<string>AccOperation = { "��������","�������","����������","�����" };



int main() 
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