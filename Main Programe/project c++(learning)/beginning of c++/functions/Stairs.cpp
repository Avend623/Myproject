#include<iostream>
using namespace std;
int h = 0;
int FStairs(int n)
{
    if (h < n)
    {
        for (int i = n; i > 0; i--)
        {
            cout<<"#";
        }
        cout<<endl;
        FStairs(--n);
    }
    h = 0;
}
int Stairs(int n)
{
    if (h < n)
    {
        for (int i = 0; i <= h; i++)
        {
            cout<<"#";
        }
        cout<<endl;
        h++;
        Stairs(n);
    }
    h = 0;
}
int main()
{
    for (int i = 0; i < 20; i++)
    {
    Stairs(10);
    FStairs(10);
    }
    

    return 0;
}