#include <iostream>
#include <random>
#include <time.h>
using namespace std;
string Name();
void guessgame(bool play);
void mathquetion(bool play);
void calc();
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
    bool play;
    cout << "hello, who is talking to me. ." << endl;
    string name = Name();
    cout << "wich do you want calc(1) or games(0):";
    cin >> play;
    if (play)
    {
        calc();
    }

    cout << "do you want to play game or exit(1/0)";
    cin >> play;
    if (play)
    {
        cout << "thank you for interesting"<<endl;
    }
    else
    {
        cout << "have a good time. .";
        system("pause");
        return 0;
    }

    cout << "hello " << name << "\ndo you want to play first game(1/0)";
    cin >> play;
    if (play)
    {
        guessgame(play);
    }
    cout << "do you want to play second game(1/0)";
    cin >> play;
    if (play)
    {
        mathquetion(play);
    }
}
string Name()
{
    cout << "enter your name:";
    string name;
    cin >> name;
    return name;
}
void calc()
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
        if (another)
        {
        }
        else
        {
            break;
        }
    }
}
void guessgame(bool play)
{
    srand(time(0));
    int guesser;
    cout << "enter number between 1 and 6:";
    cin >> guesser;
    if (guesser > rand() % 1 && guesser < rand() % 7)
    {
        cout << "correct,lucky guess " << endl;
    }
    else
    {
        cout << "wrong number.." << endl;
        while (play)
        {
            cout << "do you want to play again(1/0)";
            cin >> play;
            cout << "enter number between 1 and 6:";
            cin >> guesser;
            if (guesser > rand() % 1 && guesser < rand() % 7)
            {
                cout << "correct,lucky guess" << endl;
                break;
            }
            else
            {
                cout << "wrong number. .";
            }
        }
    }
}
void mathquetion(bool play)
{
    srand(time(0));
    while (play)
    {
        int x = rand() % 100;
        int y = rand() % 100;
        int z;
        cout << "what is the answer of quetion:" << x << "x" << y << ":";
        cin >> z;
        if (z == x * y)
        {
            cout << "good job, right answer" << endl;
            play == false;
        }
        else
        {
            cout << "sorry wrong answer" << endl;
            play == true;
        }
        cout << "do you want to play again(1/0)";
        cin >> play;
        if (play)
        {
        }
    }
}