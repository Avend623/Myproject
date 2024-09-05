#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    int hour, minute, second;
    cout << "hour:";
    cin >> hour;
    cout << "minute:";
    cin >> minute;
    cout << "second:";
    cin >> second;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int k = 0; k < 60; k++)
            {
                Sleep(1000);
                system("cls");
                cout << i << " : " << j << " : " << k << endl;
                if (i == hour && j == minute && k == second)
                {
                    break;
                }
            }
            if (i == hour && j == minute)
            {
                break;
            }
        }
        if (i == hour)
        {
            break;
        }
    }

    return 0;
}