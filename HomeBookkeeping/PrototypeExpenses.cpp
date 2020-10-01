#include "PrototypeExpenses.h"

PrototypeExpenses::PrototypeExpenses() 
{
	ExProt[Products] = new Accounting("Расходы", "Продукты");
	ExProt[Industrial] = new Accounting("Расходы", "Промтовары");
	ExProt[Transport] = new Accounting("Расходы", "Транспорт");
	ExProt[Farmacy] = new Accounting("Расходы", "Аптеки");
	ExProt[Utilitys] = new Accounting("Расходы", "Комунальные");
	ExProt[OtherExp] = new Accounting("Расходы", "Прочие");
}

Accounting* PrototypeExpenses::CloneExp(ExpensesCategory ExpCat)
{
	return ExProt[ExpCat];
}
