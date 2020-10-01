#include "Editor.h"

Editor::Editor()
{
	cost = 0;
	
}

void Editor::ShowData(Date date, string name)
{
	char CurrentPath[65000];
	_getcwd(CurrentPath, 65000);
	string path = name + '\\' + to_string(date.year) + '\\' + to_string(date.month) + '\\';
	if (_chdir(path.c_str()) == -1)
	{
		cout << "Данные для отображения отсутствуют! Введите другую дату.";
		return;
	}
	string fileName = to_string(date.day) + ".txt";
	fstream fin(fileName, ios::in);
	if (!fin.is_open())
	{
		cout << "Данные для отображения отсутствуют! Введите другую дату.";
		_chdir(CurrentPath);
		return;
	}
	else
	{
		cout << name << " от " << date.day << '/';
		cout << date.month << '/' << date.year << endl;
		int i = 1;
		while (!fin.eof())
		{
			fin >> Category;
			fin >> type;
			fin >> cost;
			if (!fin.eof())
			{
				cout << i << ". " << type << ": " << cost << " руб.(" << Category << ")\n";
			}
			i++;
		}
	}
	fin.close();
	_chdir(CurrentPath);
}

void Editor::delData(Date date, string name)
{
	char CurrentPath[65000];
	_getcwd(CurrentPath, 65000);
	string path = name + '\\' + to_string(date.year) + '\\' + to_string(date.month) + '\\';
	if (_chdir(path.c_str()) == -1)
	{
		cout << "Данные для удаления отсутствуют! Введите другую дату.";
		return;
	}
	string fileName = to_string(date.day) + ".txt";
	string fileCopy = "copy.txt";
	fstream fin(fileName, ios::in);
	fstream fout(fileCopy,ios::out|ios::app);
	if (!fin.is_open())
	{
		cout << "Данные для удаления отсутствуют! Введите другую дату.";
		_chdir(CurrentPath);
		return;
	}
	else
	{
		cout << name << " от " << date.day << '/';
		cout << date.month << '/' << date.year << endl;
		int i = 1;
		while(!fin.eof())
		{
			fin >> Category;
			fin >> type;
			fin >> cost;
			if (!fin.eof())
			{
				cout << i << ". " << type << ": " << cost << " руб.(" << Category << ")\n";
				fout << Category << endl << type << endl << cost << endl;
			}
			i++;
		}
	}
	fin.close();
	fout.close();
	int ParNumber;
	cout << "\n Введите номер пункта: ";
	cin >> ParNumber;
	fin.open(fileCopy, ios::in);
	fout.open(fileName, ios::out);
	system("cls");
	int i = 1;
	while (!fin.eof())
	{
		fin >> Category;
		fin >> type;
		fin >> cost;
		if (i == ParNumber)
		{
			i++;
			continue;
		}
		if (!fin.eof())
		{
			cout << i << ". " << type << ": " << cost << " руб.(" << Category << ")\n";
			fout << Category << endl << type << endl << cost << endl;
		}
		i++;
	}
	fin.close();
	fout.close();
	remove(fileCopy.c_str());
	_chdir(CurrentPath);
}
