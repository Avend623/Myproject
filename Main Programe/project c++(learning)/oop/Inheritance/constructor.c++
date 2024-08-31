#include<iostream>
using namespace std;
class First
{
    private:
        int x;
    public:
        First(int a)
        {
            x = a;
            cout<<"This is x value a from first(C) constructor"<<x<<endl;
        }
};
class Second : public First 
{
    private:
        int y;
    public:
        Second(int a, int b,int c,int d,int i) : First(a)
        {
            cout<<b<<endl;
        }
};
int main()
{
    Second ob2(40,52,2,5,1);
    return 0;
}