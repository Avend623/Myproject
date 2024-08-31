#include <iostream>
#include<windows.h>
using namespace std;
int main()
{
    for (int hour = 0; hour < 24; hour++)
    {
        for (int min = 0; min < 60; min++)
        {
            for (int sec = 0; sec < 60; sec++)
            {
                Sleep(1000);
                cout<<hour<<":"<<min<<":"<<sec<<endl;
            }
        }
    }
}