#include <iostream>
using namespace std;

long add(long num1, long num2)
{
    return num1 + num2;
}
long subtruct(long num1, long num2)
{
    return num1 - num2;
}
long multiply(long num1, long num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    if (num2 != 0)
    {
        return num1 / num2;
    }
    else
    {
        cout << "Error : cannot divide by zero" << endl;
        return 0;
    }
}
int main()
{

    int x = 10;
    while (x == 10)
    {
        char symbol;
        cout << "enter your symbol(+, -, *, /) or factorolize{f}:";
        cin >> symbol;
        if (symbol == 'f' || symbol == 'F')
        {
            int x;
            cout << "--------    factrolizing    --------" << endl
                 << "enter your number:";
            cin >> x;
            for (int i = x; i > 0; i--)
            {
                if (i == x)
                {
                    continue;
                }
                x *= i;
            }
            cout << "equal = " << x << endl;
        }
        if (symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        {
            long num1, num2;
            cout << "Enter your first number: ";
            cin >> num1;
            cout << "Enter your second number: ";
            cin >> num2;
            switch (symbol)
            {
            case '+':
                cout << "Result: " << add(num1, num2) << ".." << endl;
                break;
            case '/':
                cout << "Result: " << divide(num1, num2) << ".." << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << ".." << endl;
                break;
            case '-':
                cout << "Result: " << subtruct(num1, num2) << ".." << endl;
                break;
            default:
                if (symbol != 'f' && symbol != 'F')
                {
                    cout << "Invalid symbol. Please try again." << endl;

                    cout << "write any charecter to exit. . .";
                }
            }
        }
        else
        {
        }
        bool another;
        cout << "Do you want another calculate.. ";
        cin >> another;
        if(another)
        {
        }
        else
        {
            break;
        }
    }
    cout << "write any charecter to exit. . .";
    cin.ignore();
    int waiting;
    cin >> waiting;
    if (waiting == 0)
    {
        free;
        return 0;
    }
    return 0;
}
