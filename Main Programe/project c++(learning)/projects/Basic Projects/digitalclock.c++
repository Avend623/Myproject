#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
    int hrs, min, sec;
    cout << "Hours:";
    cin >> hrs;
    cout << "minutes:";
    cin >> min;
    cout << "seconds:";
    cin >> sec;
    while (true)
    {
        system("cls");
        if (sec > 59)
        {
            min++;
            sec = 0;
        }
        if (min > 59)
        {
            hrs++;
            min = 0;
        }
        if (hrs > 23)
        {
            hrs = 0;
        }
        cout << hrs << " : " << min << " : " << sec << endl;
        sec++;
        Sleep(900);
    }
}