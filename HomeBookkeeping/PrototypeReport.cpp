#include "PrototypeReport.h"

PrototypeReport::PrototypeReport()
{
	prototypeReport[EXPENSES] = new Report("Расходы");
	prototypeReport[INCOME] = new Report("Доходы");
}

void PrototypeReport::setCatReport(CatReport CatRep, vector<string> CatForRep)
{
	prototypeReport[CatRep]->SetCategoryReport(CatForRep);
}

Report PrototypeReport::Clone(CatReport CatRep)
{
	return *prototypeReport[CatRep];
}
