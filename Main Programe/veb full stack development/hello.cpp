#include <iostream>
using namespace std;
int main()
{
    int time;
    cout << "what is the time now??";
    cin >> time;
    if (time < 18)
    {
        cout << "good morning\n";
    }
    else
    {
        cout << "good evening\n" << endl;
    }
    
    
    cout << "press any key to countinue. . .";

    int waiting;

    cin >> waiting;
}