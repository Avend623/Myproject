#include <iostream>
using namespace std;
class Calc
{
private:
    int num;

public:
    void setValues()
    {
        cout << "enter your num:";
        cin >> num;
    }
    int operator+(Calc ob)
    {
        return num + ob.num;
    }
    int operator-(Calc ob)
    {
        return num - ob.num;
    }
    int operator*(Calc ob)
    {
        return num * ob.num;
    }
    int operator/(Calc ob)
    {
        if (ob.num == 0)
        {
            cout<<"cannot divide by zero!"<<endl;
            return 0;
        }        
        else
        {
            return num / ob.num;
        }
    }
    bool operator ==(Calc ob)
    {
        if (num == ob.num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void operator =(Calc ob)
    {
        num = ob.num;
    }
};
int main()
{
    Calc ob1;
    ob1.setValues();
    Calc ob2;
    ob2.setValues();
    ob1 = ob2;
    char symbol;
    cout << "enter your symbol for obs:";
    cin >> symbol;
    switch (symbol)
    {
    case '+':
        cout << "ob1 + ob2 = " << ob1 + ob2 << endl;
        break;
    case '-':
        cout << "ob1 - ob2 = " << ob1 - ob2 << endl;
        break;
    case '*':
        cout << "ob1 * ob2 = " << ob1 * ob2 << endl;
        break;
    case '/':
        cout << "ob1 / ob2 = " << ob1 / ob2 << endl;
        break;
    default:
        cout << "wrong symbol!" << endl;
        break;
    }
    if (ob1 == ob2)
    {
        cout<<"hello world"<<endl;
    }
    else
    {
        cout<<"not equal"<<endl;
    }
    
    return 0;
}