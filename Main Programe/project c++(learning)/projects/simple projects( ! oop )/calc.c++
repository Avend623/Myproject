#include <iostream>
using namespace std;
double num1, num2;
double sum()
{
    return num1 + num2;
}
double mines()
{
    return num1 - num2;
}
double divide()
{
    if (num2 == 0)
    {
        cout<<"wrong equaltion!"<<endl;
        return 0;
    }
    
    return num1 / num2;
}
double multiply()
{
    return num1 * num2;
}
int main()
{
    bool exit;
    char symbol;
    do
    {
        cout << "Enter your first num:";
        cin >> num1;
        cout << "Enter your second num:";
        cin >> num2;
        cout << "1.Plus(+)\n2.minus(-)\n3.multiply\n4.divide(/)\n";
        cout << "enter your symbol?";
        cin >> symbol;
        switch (symbol)
        {
        case '+':
            cout<<"equal:"<<sum()<<endl;
            break;
        case '-':
            cout<<"equal:"<<mines()<<endl;
            break;
        case '/':
            cout<<"equal:"<<divide()<<endl;
            break;
        case '*':
            cout<<"equal:"<<multiply()<<endl;
            break;
        default:
            cout << "wrong char!" << endl;
            break;
        }
        while (true)
        {
            cout << "do you want another one(y/n)?";
            cin >> symbol;
            if (symbol == 'y' || symbol == 'Y')
            {
                exit = true;
                break;
            }
            else if (symbol == 'n' || symbol == 'N')
            {
                exit = false;
                break;
            }
            else
            {
                cout<<"wrong!"<<endl;
            }
        }
    } while (exit);
    system("pause");
    return 0;
}