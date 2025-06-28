#include<windows.h>
#include<iostream>
using namespace std;
int main()
{
    //* That is how to do delay easier in using "Slepp()" function 
    string you;
    int value = 0;
    int second[1000];
    for (int i = 0; i < 10; i++)
    {
        value += 1000;
        second[i] =  value; 
    }
    
    cout<<"you:";
    cin>>you;















    Sleep(second[1]);//* That's Sleep function from "windows.h" library but becareful! They using miliseconds I used a way to use seconds
    cout<<"World:";
    Sleep(second[1]);
    cout<<"I have boyfriend"<<endl;
    Sleep(second[1]/4);
    system("pause");
    return 0;
}