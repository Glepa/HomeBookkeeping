#include "PrototypeIncome.h"
#include "GlobalDate.h"
PrototypeIncome::PrototypeIncome()
{
	IncProt[Salary] = new Accounting("������", "��������");
	IncProt[OtherInc] = new Accounting("������", "������");
}

Accounting* PrototypeIncome::CloneInc(IncomeCategory IncCat)
{
	return IncProt[IncCat];
}
