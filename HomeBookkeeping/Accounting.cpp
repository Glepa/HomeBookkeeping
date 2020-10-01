#include"Accounting.h"



Accounting::Accounting(const string name_, const string category_)
{
	name = name_;
	category = category_;
	date.day = 0;
	date.month = 0;
	date.year = 0;
	type = " ";
	cost = 0;
}

void Accounting::setDate(Date date_)
{
	date = date_;
}

void Accounting::writeData(string type_, double cost_)
{
	type = type_;
	cost = cost_;
	char CurrentPath[65000];
	_getcwd(CurrentPath,65000);
	string fileName = to_string(date.day) + ".txt";
	string path = name + '\\';
	if (_chdir(path.c_str()) == -1)
	{
		_mkdir(path.c_str());
		_chdir(path.c_str());
	}
	path = to_string(date.year) + '\\';
	if (_chdir(path.c_str()) == -1)
	{
		_mkdir(path.c_str());
		_chdir(path.c_str());
	}
	path = to_string(date.month) + '\\';
	if (_chdir(path.c_str()) == -1)
	{
		_mkdir(path.c_str());
		_chdir(path.c_str());
	}
	fstream fout(fileName,ios::out | ios::app);
	if (!fout.is_open()) cout << "\n Данные не записались, повторите ввод!";
	else
	{
		fout <<category<<endl<< type << endl << cost<<endl;
	}
	fout.close();
	_chdir(CurrentPath);

}

void Accounting::show()
{
	system("cls");
	system("Color 61");
	string fileName = name + '\\' + to_string(date.year) + '\\'
	+ to_string(date.month) + '\\' + to_string(date.day) + ".txt";
	fstream fin(fileName, ios::in);
	if (!fin.is_open()) cout << "\n Данные Отсутствуют!!!";
	else
	{
		cout << endl << setfill('0') << setw(2) << date.day << '.';
		cout << setfill('0') << setw(2) << date.month << '.' << date.year << endl;
		int i = 1;
		while(!fin.eof())
		{
			fin >> category;
			fin >> type;
			fin >> cost;
			if (!fin.eof()) 			
			cout << i << ". " << type << " : " << cost << " руб.(" << category << ")\n";
			i++;
		}
	}
	fin.close();
}

Accounting::~Accounting()
{
}
