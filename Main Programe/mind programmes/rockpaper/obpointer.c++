#include <iostream>
#include <ctime>
#include <random>
using namespace std;
int main()
{
    srand(time(0));
    bool repeat = true;
    int type = rand() % 3;
    char Cchoise;
    char choise;
    while (repeat)
    {
        type = rand()%3;
        cout << "enter your one..(P/R/S)";
        cin >> choise;
        switch (type)
        {
        case 0:
            Cchoise = 'P';
            cout << "Computer:" << Cchoise << endl;
            break;
        case 1:
            Cchoise = 'R';
            cout << "Computer:" << Cchoise << endl;
            break;
        case 2:
            Cchoise = 'S';
            cout << "Computer:" << Cchoise << endl;
            break;
        default:
            break;
        }
        if (Cchoise == choise)
        {
            cout << "Tie!" << endl;
        }
        else if ((Cchoise == 'S' && (choise == 'R' || choise == 'r')) || (Cchoise == 'R' && (choise == 'P' || choise == 'p')) || (Cchoise == 'P' && (choise == 'S' || choise == 's')))
        {
            cout << "You win!" << endl;
        }
        else if ((Cchoise == 'R' && (choise == 'S' || choise == 's')) || (Cchoise == 'P' && (choise == 'R' || choise == 'r')) || (Cchoise == 'S' && (choise == 'P' || choise == 'p')))
        {
            cout << "You lose!" << endl;
        }
        else
        {
            cout << "wrong char.." << endl;
        }
        cout << "do you want to try again(1/0)?";
        cin >> repeat;
    }
}