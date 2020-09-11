#include"Expenses.h"

int main() {
	int c;
	
	while (cin >> c&&c) {
		switch (c) {
		case 1: {
			Expenses ex("Aplle", "Food");
			ex.addCost(37.78);
			Expenses ex3("Orange", "Food");
			ex3.addCost(45.55);
			//ex.delCost(1);
			break;
		}
		case 2: {
			Expenses ex2("Poroshock", "Prom");
			ex2.addCost(66.25);
			Expenses ex4("Fary", "Prom");
			ex4.addCost(74.42);
			//ex2.delCost(1);
			break;
		}
		}
	}
	return 0;
}