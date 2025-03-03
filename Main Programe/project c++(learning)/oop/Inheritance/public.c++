#include<iostream>
using namespace std;
class First 
{
    public:
        int x = 10;

};
class Second : public First
{
};
int main()
{
    Second ob1;
    cout<<ob1.x;


    return 0;
}