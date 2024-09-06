#include <iostream>
#include <windows.h>
using namespace std;
static double balance = 1020.60;
void psswd()
{
    char choice;
    int password;
    cout << "\n Enter your password:";
    cin >> password;
    if (password == 10)
    {
        cout << "correct password!" << endl;
    }
    else
    {
        cout << "wrong password!" << endl;
        while (true)
        {
            cout << "Do you want to try again(y/n)?";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter your password:";
                cin >> password;
                if (password == 10)
                {
                    cout << "correct password!" << endl;
                    break;
                }
            }
            else if (choice == 'n' || choice == 'N')
            {
                exit(0);
            }
            else
            {
                cout << "wrong char!" << endl;
            }
        }
    }
    cout << "please wait. . .";
    Sleep(1000);
    cout << endl;
    Sleep(1500);
}
int Withdraw()
{
    double withdraw;
    cout << "how much:";
    cin >> withdraw;
    if (withdraw > balance)
    {
        cout << "not enough balance!" << endl;
        return 0;
    }
    balance -= withdraw;
    cout << "Your balance now is " << balance << "$" << endl;
}
int Deposit()
{
    double deposit;
    cout << "how much:";
    cin >> deposit;
    if (deposit > 2500)
    {
        cout << "you can't deposit more than 2500$!" << endl;
        return 0;
    }
    balance += deposit;
    cout << "Your balance now is " << balance << "$" << endl;
}
void Balance()
{
    cout << "Your balance is " << balance << "$" << endl;
}
int main()
{
    int choise;
    cout << "Welcome Avend!";
    psswd();
    while (true)
    {
        cout << "1-balance" << endl;
        cout << "2-withdraw" << endl;
        cout << "3-deposit" << endl;
        cout << "4-exit" << endl;
        cout << "what do you want?";
        cin >> choise;
        cout << "please wait..." << endl;
        Sleep(250);
        switch (choise)
        {
        case 1:
            Balance();
            break;
        case 2:
            Withdraw();
            break;
        case 3:
            Deposit();
            break;
        case 4:
            return 0;
        default:
            cout << "wrong choise" << endl;
        }
    }
    return 0;
}