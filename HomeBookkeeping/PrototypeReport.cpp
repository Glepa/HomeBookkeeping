#include "PrototypeReport.h"

PrototypeReport::PrototypeReport()
{
	prototypeReport[EXPENSES] = new Report("�������");
	prototypeReport[INCOME] = new Report("������");
}

void PrototypeReport::setCatReport(CatReport CatRep, vector<string> CatForRep)
{
	prototypeReport[CatRep]->SetCategoryReport(CatForRep);
}

Report PrototypeReport::Clone(CatReport CatRep)
{
	return *prototypeReport[CatRep];
}
