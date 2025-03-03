#include <iostream>
using namespace std;
int main()
{
    int range;
    cout << "your range:";
    cin >> range;
    int ages[range];
    for (int i = 0; i < range; i++)
    {
        cout << "enter your ages[" << i << "]:";
        cin >> ages[i];
    }
    for (int i = 0; i < range; i++)
    {
        printf("ages[%i] = %i \n", i, ages[i]);
    }
}