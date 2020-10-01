#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
#include<conio.h>
#include<vector>
#include<windows.h>
#include"GlobalDate.h"

using namespace std;

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

#define Enter 13
#define YES 89
#define NO 78
#define Up 72
#define Down 80
#define Esc 27
class Menu
{
    string NamePrg;
    vector <string> menu_item;
    vector <COORD> coord_menu;
    int button;
    int numPos;
    HANDLE hout;
    HANDLE hin;
    COORD point;
    CONSOLE_CURSOR_INFO cursor;
    CONSOLE_FONT_INFOEX font;
public:
    Menu(string nameProg);
    int StartMenu(string name = "");
    Date EnterDate();
    Date EnterMonth();
    Date EnterYear();
    void setData(string& type, double& cost);
    void setCoord(vector<COORD>coord);
    void setItemMenu(vector<string> IMenu);
};