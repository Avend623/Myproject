#include <iostream>
using namespace std;
class Cal
{
private:
    int n1;
    int n2;
public:
    Cal()
    {
        cout << "n1:";
        cin >> n1;
        cout << "n2:";
        cin >> n2;
    }
    Cal(int x, int y)
    {
        n1 = x;
        n2 = y;
    }
    int sum()
    {
        return n1 + n2;
    }
    int mul()
    {
        return n1 * n2;
    }
    float div()
    {
        return (float)n1 / n2;//* typecast
    }
    int mod()
    {
        return n1 % n2;
    }
};
int main()
{
    Cal ob1;
    Cal ob2();
    cout<<"sum:"<<ob1.sum()<<endl;
    cout<<"div:"<<ob1.div()<<endl;
    cout<<"mul:"<<ob1.mul()<<endl;
    cout<<"mod:"<<ob1.mod()<<endl;
    return 0;
}