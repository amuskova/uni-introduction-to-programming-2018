#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

int* func(int N)
{
    int m=N;
    int i=0;
    while(N!=0)
    {
        N=N/10;
        i++;
    }
    int *arr=new int[i];
    for(int k=i-1; k>=1; k--)
    {
        arr[k]=m%10;
        m=m/10;
    }
    arr[0]=m;

    return arr;
}

int main()
{
    int number = 0;
    while (number >= -65000 && number <=65000)
    {
        cout << "Type a number in [-65000; 65000]: ";
        cin >> number;
        int help = number;
        if (cin.fail())
        {
            std::cout << "Wrong input!" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return 0;
        }
        if (number >= -65000 && number <= 65000)
        {
            int lenght = 0;
            while (help != 0)
            {
                lenght++;
                help = help/10;
            }

            int* arr = func(number);

            cout << "Digits: ";
            for (int i = 0; i < lenght; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            delete arr;
        }
        else
        {
            cout << "Wrong number!" << endl;
            return 0;
        }
    }

    return 0;
}
