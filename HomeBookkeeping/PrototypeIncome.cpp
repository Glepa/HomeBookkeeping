#include "PrototypeIncome.h"
#include "GlobalDate.h"
PrototypeIncome::PrototypeIncome()
{
	IncProt[Salary] = new Accounting("Доходы", "Зарплата");
	IncProt[OtherInc] = new Accounting("Доходы", "Прочие");
}

Accounting* PrototypeIncome::CloneInc(IncomeCategory IncCat)
{
	return IncProt[IncCat];
}
