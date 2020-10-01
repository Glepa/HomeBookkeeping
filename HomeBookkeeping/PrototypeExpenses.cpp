#include "PrototypeExpenses.h"

PrototypeExpenses::PrototypeExpenses() 
{
	ExProt[Products] = new Accounting("�������", "��������");
	ExProt[Industrial] = new Accounting("�������", "����������");
	ExProt[Transport] = new Accounting("�������", "���������");
	ExProt[Farmacy] = new Accounting("�������", "������");
	ExProt[Utilitys] = new Accounting("�������", "�����������");
	ExProt[OtherExp] = new Accounting("�������", "������");
}

Accounting* PrototypeExpenses::CloneExp(ExpensesCategory ExpCat)
{
	return ExProt[ExpCat];
}
