#include"Menu.h"

using namespace std;


Menu::Menu(string nameProg)
{
	NamePrg = nameProg;
	button = 0;
	numPos = 0;
	point.X = 0;
	point.Y = 0;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	hin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleDisplayMode(hout, 1, 0);
	GetCurrentConsoleFontEx(hout, TRUE, &font);
	GetConsoleCursorInfo(hout, &cursor);
	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 22;
	font.FontWeight = 700;
	SetCurrentConsoleFontEx(hout, TRUE, &font);
}

int Menu::StartMenu(string namePos)			
{

	numPos = 0;
	system("cls");
	system("Color 61");
	point.X = 53; point.Y = 1;
	SetConsoleCursorPosition(hout, point);
	cout << NamePrg;
	point.X = 50; point.Y = 10;
	SetConsoleCursorPosition(hout, point);
	cout << namePos;
	for (int i = 0; i < menu_item.size(); i++)
	{
		SetConsoleCursorPosition(hout, coord_menu[i]);
		if (!i) SetConsoleTextAttribute(hout, Red << 4 | Blue);
		else SetConsoleTextAttribute(hout, Brown << 4 | Blue);
		cout << menu_item[i];
	}
	SetConsoleCursorPosition(hout, coord_menu[0]);
	while (true) {
		button = _getch();
		switch (button) {
		case Up: {
			if (numPos > 0) {
				SetConsoleCursorPosition(hout, coord_menu[numPos]);
				SetConsoleTextAttribute(hout, Brown << 4 | Blue);
				cout << menu_item[numPos];
				numPos--;
				SetConsoleCursorPosition(hout, coord_menu[numPos]);
				SetConsoleTextAttribute(hout, Red << 4 | Blue);
				cout << menu_item[numPos];
			}break;
		}
		case Down: {
			if (numPos < menu_item.size() - 1) {
				SetConsoleCursorPosition(hout, coord_menu[numPos]);
				SetConsoleTextAttribute(hout, Brown << 4 | Blue);
				cout << menu_item[numPos];
				numPos++;
				SetConsoleCursorPosition(hout, coord_menu[numPos]);
				SetConsoleTextAttribute(hout, Red << 4 | Blue);
				cout << menu_item[numPos];
			}break;
		}
		case Enter: {
			system("cls");
			system("Color 61");
			button = 0;
			return numPos;
		}
		}
	}
}

Date Menu::EnterDate()
{
	system("cls");
	system("Color 61");
	cout.fill(' ');
	Date date{ 0,0,0 };
	time_t Time = time(NULL);
	tm LocalDate;
	localtime_s(&LocalDate, &Time);
	point.X = 5; point.Y = 32;
	SetConsoleCursorPosition(hout, point);
	cout << "\"Enter\" - Выбор" << setw(30) << "\\/" << " /\\" << " - Прокрутка даты  " << setw(30) << "\"ESC\" - Назад";
	point.X = 53; point.Y = 10;
	SetConsoleCursorPosition(hout, point);
	cout << " Выбор даты: ";
	point.X = 30; point.Y += 3;
	SetConsoleCursorPosition(hout, point);
	cout << "День:" << setw(30) << "Месяц:" << setw(30) << "Год:";
	point.X += 5;
	SetConsoleCursorPosition(hout, point);
	date.day = LocalDate.tm_mday;
	SetConsoleTextAttribute(hout, Brown << 4 | Red);
	cout << setfill('0') << setw(2) << date.day;
	button = 0;
	while (button != Enter)
	{
		button = _getch();
		switch (button)
		{
		case Up:
		{
			if (date.day > 1)
			{
				date.day--;
				SetConsoleCursorPosition(hout, point);
				cout << setfill('0') << setw(2) << date.day;
			}
			break;
		}
		case Down:
		{
			if (date.day < 31)
			{
				date.day++;
				SetConsoleCursorPosition(hout, point);
				cout << setfill('0') << setw(2) << date.day;
			}
			break;
		}
		case Enter:
		{
			break;
		}
		case Esc:
		{
			system("cls");
			system("Color 61");
			date.day = 0;
			return date;
		}
		}
	}
	button = 0;
	SetConsoleCursorPosition(hout, point);
	cout << setfill('0') << setw(2) << date.day;
	point.X += 30;
	SetConsoleCursorPosition(hout, point);
	date.month = LocalDate.tm_mon + 1;
	cout << setfill('0') << setw(2) << date.month;
	while (button != Enter) 
	{
		button = _getch();
		switch (button)
		{
		case Up:
		{
			if (date.month > 1)
			{
				date.month--;
				SetConsoleCursorPosition(hout, point);
				cout << setfill('0') << setw(2) << date.month;
			}
			break;
		}
		case Down:
		{
			if (date.month < 12)
			{
				date.month++;
				SetConsoleCursorPosition(hout, point);
				cout << setfill('0') << setw(2) << date.month;
			}
			break;
		}
		case Enter: 
		{

			break;
		}
		case Esc:
		{
			system("cls");
			system("Color 61");
			date.day = 0;
			return date;
		}
		}
	}
	button = 0;
	SetConsoleCursorPosition(hout, point);
	cout << setfill('0') << setw(2) << date.month;
	point.X += 30;
	SetConsoleCursorPosition(hout, point);
	date.year = 1900 + LocalDate.tm_year;
	cout << date.year;
	while (button != Enter) 
	{
		button = _getch();
		switch (button)
		{
		case Up:
		{
			if (date.year > 0)
			{
				date.year--;
				SetConsoleCursorPosition(hout, point);
				cout << date.year;
			}
			break;
		}
		case Down:
		{
			if (date.year < 3000)
			{
				date.year++;
				SetConsoleCursorPosition(hout, point);
				cout << date.year;
			}
			break;
		}
		case Enter: {
			system("cls");
			system("Color 61");
			break;
		}
		case Esc:
		{
			system("cls");
			system("Color 61");
			date.day = 0;
			return date;
		}
		}
	}
	return date;
}


Date Menu::EnterMonth()
{
	system("cls");
	system("Color 61");
	cout.fill(' ');
	Date date{ 0,0,0 };
	time_t Time = time(NULL);
	tm LocalDate;
	localtime_s(&LocalDate, &Time);
	point.X = 5; point.Y = 32;
	SetConsoleCursorPosition(hout, point);
	cout << "\"Enter\" - Выбор" << setw(30) << "\\/" << " /\\" << " - Прокрутка даты  " << setw(30) << "\"ESC\" - Назад";
	point.X = 53; point.Y = 10;
	SetConsoleCursorPosition(hout, point);
	cout << " Выбор даты: ";
	point.X = 30; point.Y += 3;
	SetConsoleCursorPosition(hout, point);
	cout << "Месяц:" << setw(30) << "Год:";
	point.X += 7;
	SetConsoleCursorPosition(hout, point);
	button = 0;
	date.month = LocalDate.tm_mon + 1;
	cout << setfill('0') << setw(2) << date.month;
	while (button != Enter) {
		button = _getch();
		switch (button)
		{
		case Up:
		{
			if (date.month > 1)
			{
				date.month--;
				SetConsoleCursorPosition(hout, point);
				cout << setfill('0') << setw(2) << date.month;
			}
			break;
		}
		case Down:
		{
			if (date.month < 12)
			{
				date.month++;
				SetConsoleCursorPosition(hout, point);
				cout << setfill('0') << setw(2) << date.month;
			}
			break;
		}
		case Enter: {
			break;
		}
		case Esc:
		{
			system("cls");
			system("Color 61");
			date.day = 0;
			return date;
		}
		}
	}
	button = 0;
	SetConsoleCursorPosition(hout, point);
	cout << setfill('0') << setw(2) << date.month;
	point.X += 30;
	SetConsoleCursorPosition(hout, point);
	date.year = 1900 + LocalDate.tm_year;
	cout << date.year;
	while (button != Enter) {
		button = _getch();
		switch (button)
		{
		case Up:
		{
			if (date.year > 0)
			{
				date.year--;
				SetConsoleCursorPosition(hout, point);
				cout << date.year;
			}
			break;
		}
		case Down:
		{
			if (date.year < 3000)
			{
				date.year++;
				SetConsoleCursorPosition(hout, point);
				cout << date.year;
			}
			break;
		}
		case Enter: {
			system("cls");
			system("Color 61");
			break;
		}
		case Esc:
		{
			system("cls");
			system("Color 61");
			date.day = 0;
			return date;
		}
		}
	}
	return date;
}

Date Menu::EnterYear()
{
	system("cls");
	system("Color 61");
	cout.fill(' ');
	Date date{ 0,0,0 };
	time_t Time = time(NULL);
	tm LocalDate;
	localtime_s(&LocalDate, &Time);
	point.X = 5; point.Y = 32;
	SetConsoleCursorPosition(hout, point);
	cout << "\"Enter\" - Выбор" << setw(30) << "\\/" << " /\\" << " - Прокрутка даты  " << setw(30) << "\"ESC\" - Назад";
	point.X = 53; point.Y = 10;
	SetConsoleCursorPosition(hout, point);
	cout << " Выбор года: ";
	point.X = 30; point.Y += 3;
	SetConsoleCursorPosition(hout, point);
	cout << "Год:";
	point.X += 5;
	SetConsoleCursorPosition(hout, point);
	button = 0;
	date.year = 1900 + LocalDate.tm_year;
	cout << date.year;
	while (button != Enter) {
		button = _getch();
		switch (button)
		{
		case Up:
		{
			if (date.year > 0)
			{
				date.year--;
				SetConsoleCursorPosition(hout, point);
				cout << date.year;
			}
			break;
		}
		case Down:
		{
			if (date.year < 3000)
			{
				date.year++;
				SetConsoleCursorPosition(hout, point);
				cout << date.year;
			}
			break;
		}
		case Enter: {
			system("cls");
			system("Color 61");
			break;
		}
		case Esc:
		{
			system("cls");
			system("Color 61");
			date.day = 0;
			return date;
		}
		}
	}
	return date;
}

void Menu::setData(string& type, double& cost)
{
	system("cls");
	system("Color 61");
	cout.fill(' ');
	point.X = 53; point.Y = 10;
	SetConsoleCursorPosition(hout, point);
	cout << " << Ввод данных >> ";
	point.X = 20; point.Y += 3;
	SetConsoleCursorPosition(hout, point);
	cout << "Наименование:";
	point.Y += 2;
	SetConsoleCursorPosition(hout, point);
	cout << "Колличество денежных средств:";
	point.X += 14;
	point.Y -= 2;
	SetConsoleCursorPosition(hout, point);
	SetConsoleTextAttribute(hout, Brown << 4 | Red);
	cin >> type;
	cin.clear();
	cin.ignore(sizeof(double), '\n');
	point.Y += 2;
	point.X += 16;
	SetConsoleCursorPosition(hout, point);
	while (!(cin >> cost))
	{
		SetConsoleCursorPosition(hout, point);
		cout << "                          ";
		cout << "                          ";
		cin.clear();
		cin.ignore(sizeof(double), '\n');
		SetConsoleCursorPosition(hout, point);

	}
}

void Menu::setCoord(vector<COORD> coord)
{
	coord_menu.assign(coord.begin(), coord.end());
}

void Menu::setItemMenu(vector<string> IMenu)
{
	menu_item.assign(IMenu.begin(), IMenu.end());
}


