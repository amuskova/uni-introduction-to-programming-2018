#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char date[11];
    cout << "Input date: ";
    cin >> date;

    if (strlen(date) != 10)
    {
        cout << "Error in length!" << endl;
        return 0;
    }

    for (int i = 0; i < strlen(date); i++)
    {
        if ((date[i] >= '0' && date[i] <= '9') || date[i] == '.')
        {

        }
        else
        {
            cout << "Not correct!" << endl;
            return 0;
        }
    }

    int counterDot = 0;
    for (int i = 0; i < strlen(date); i++)
    {
        if (date[i] == '.')
        {
            counterDot++;
        }
    }
    if (counterDot != 2)
    {
        cout << "Not correct!" << endl;
        return 0;
    }

    //check for number of numbers
    int counterNumber = 0;
    for (int i = 0; i < strlen(date); i++)
    {
        if (date[i] != '.')
        {
            counterNumber++;
        }
        else
        {
            if (counterNumber != 2)
            {
                cout << "Not correct!" << endl;
                return 0;
            }
            counterNumber = 0;
        }
        if (i == strlen(date)-1)
        {
            if (counterNumber != 4)
            {
                cout << "Not correct!" << endl;
                return 0;
            }
        }
    }
    int day = 0;
    int month = 0;
    int year = 0;
    for (int i = 0; i < strlen(date); i++)
    {
        if (i == 0)
        {
            day += (date[i]-48)*10;
        }
        else if (i == 1)
        {
            day += date[i]-48;
        }
        else if (i == 3)
        {
            month += (date[i]-48)*10;
        }
        else if (i == 4)
        {
            month += date[i]-48;
        }
        else if (i == 6)
        {
            year += (date[i]-48)*1000;
        }
        else if (i == 7)
        {
            year += (date[i]-48)*100;
        }
        else if (i == 8)
        {
            year += (date[i]-48)*10;
        }
        else if (i == 9)
        {
            year += date[i]-48;
        }
        if (i == strlen(date)-1)
        {
            if (year < 1 || year > 9999)
            {
                cout << "Not correct year!" << endl;
                return 0;
            }
            if (month < 1 || month > 12)
            {
                cout << "Not correct month!" << endl;
                return 0;
            }
            if (year%4 == 0 && month == 2)
            {
                if (day < 1 || day > 29)
                {
                    cout << "Not a correct day!" << endl;
                    return 0;
                }
            }
            if (year%4 != 0 && month == 2)
            {
                if (day < 1 || day > 28)
                {
                    cout << "Not a correct day!" << endl;
                    return 0;
                }
            }
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if (day < 1 || day > 31)
                {
                    cout << "Not a correct day!" << endl;
                    return 0;
                }
            }
            if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                if (day < 1 || day > 30)
                {
                    cout << "Not a correct day!" << endl;
                    return 0;
                }
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= year; i++)
    {
        if (i == year)
        {
            for (int j = 1; j <= month; j++)
            {
                if (j == month)
                {
                    answer += day-1;
                }
                else
                {
                    if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
                    {
                        answer += 31;
                    }
                    if (j == 4 || j == 6 || j == 9 || j == 11)
                    {
                        answer += 30;
                    }
                    if (j == 2)
                    {
                        if (i%4 == 0)
                        {
                            answer += 29;
                        }
                        else
                        {
                            answer += 28;
                        }
                    }
                }
            }
        }
        else
        {
            if (i%4 == 0)
            {
                answer += 366;
            }
            else
            {
                answer += 365;
            }
        }
    }
    cout<<"Days from 01.01.0001 is: "<<answer<<endl;
    return 0;
}
