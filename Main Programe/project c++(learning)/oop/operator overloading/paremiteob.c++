#include <iostream>
using namespace std;
static int count = 0;
class Dontworry
{
private:
    int x = 0;

public:
    Dontworry()
    {
        count++;
        cout << "******* object " << count << " *******" << endl;
    }
    void getValues()
    {
        cout << "enter x:";
        cin >> x;
    }
    void compare(Dontworry ob2)
    {
        if (x == ob2.x)
        {
            cout << x << " == " << ob2.x << endl;
        }
        else
        {
            cout << x << " != " << ob2.x << endl;
        }
    }
};
int main()
{
    Dontworry ob1;
    ob1.getValues();
    Dontworry ob2;
    ob2.getValues();
    ob1.compare(ob1);
}