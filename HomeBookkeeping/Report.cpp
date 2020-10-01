#include "Report.h"

Report::Report(const string name_)
{
    name = name_;
    total = 0;
}

void Report::DayReport(Date date)
{
    char CurrentPath[65000];
    _getcwd(CurrentPath, 65000);
    string path = name + '\\' + to_string(date.year) + '\\' + to_string(date.month) + '\\';
    if (_chdir(path.c_str()) == -1) return;
    string category;
    double summ;
    string fileName = to_string(date.day) + ".txt";
        fstream inout(fileName, ios::in);
        if (!inout.is_open())
        {
            _chdir(CurrentPath);
            return;
        }
        else
        {
            while (!inout.eof())
            {
                inout>>category;
                inout>>type;
                inout >> summ;
                if (!inout.eof())
                {
                    if (report.count(category))
                        report[category] += summ;
                    else
                        report[category] = summ;
                    total += summ;
                }
            }
        }
        inout.close();
        _chdir(CurrentPath);
}

void Report::MonthReport(Date date)
{
     date.day = 1;
   
    for (; date.day <= 31; date.day++)
    {
        DayReport(date);
    }
    
}

void Report::YearReport(Date date)
{
     date.month = 1;
    for (; date.month <= 12; date.month++)
    {
        MonthReport(date);
    }
}

void Report::PeriodReport(Date start, Date finish)
{
    while (start.year < finish.year) {
        YearReport(start);
        start.day = 1;
        start.month = 1;
        start.year++;
    }
    while (start.month < finish.month) {
        MonthReport(start);
        start.day = 1;
        start.month ++;
    }
    while (start.day < finish.day) {
       DayReport(start);
        start.day++;
    }
}

void Report::SetCategoryReport(vector<string> catRep)
{
    for (string& str : catRep)
    {
        report[str] = 0;
    }
}

void Report::showReport()
{
    cout.fill(' ');
    for (pair<string,double> par: report)
    {
       
        cout << endl<<"  " << setw(5) << par.first 
            <<setw(30 - par.first.size())<< par.second << " руб.";
        par.first.clear();
        par.second = 0;
    }
    cout << "\n\n   Итого: " << total;
}

Report::~Report()
{
}




