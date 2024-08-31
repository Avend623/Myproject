#include <iostream>
#include <random>
using namespace std;

int main()
{

    cout << "Hello, who is talking to me..." << endl;

    cout << "What is your name? ";
    string name;
    cin >> name;
    cout << "Oh, what a name! Hello, " << name << "!" << endl;
    cout << "Do you want to play a game? Say 0 (F) or 1 (T) : ";
    bool playGame;
    cin >> playGame;
    if (playGame == true)
    {
        cout << "Thank you! I am glad! Let's play..." << endl;
        cout << "Select a number from 1 to 6: ";
        bool TRUE;
        int guessing = 7;
        int guesser;
        cin >> guesser;
        if (guesser > rand() % 1 && guesser <= rand() % 6)
        {
            cout << "Correct! What a lucky guess!" << endl;
            TRUE = true;
        }
        else
        {
            cout << "Oh, sorry! Wrong number." << endl;
        }
        if (TRUE == false)
        {
            bool trying = true;
            while (trying)
            {
                cout << "Do you want to play again? Say 1 (T) or 0 (F): ";
                cin >> trying;
                if (trying)
                {
                    cout << "Select a number from 1 to 10: ";
                    cin >> guesser;
                }
                if (TRUE)
                {
                    cout << "Correct! What a lucky guess!" << endl;
                    break;
                }
            }
        }
        bool agame;
        cout << "do you want to play another game?..";
        cin >> agame;
        if (agame)
        {
            cout << "her we go..";
            cout << "I will ask you math quetions\n";
            int answer;
            cout << "what is equal 8 multiply 4:";
            cin >> answer;
            if (answer == 32)
            {
                cout << "correct!!\n";
            }
            else
            {
                cout << "oh.. I am sorry??you are wrong!!" << endl;
            }
        }
        else
        {
            cout << "Oh, no problem! Have a good time." << endl;
            return 1;
        }
    }
    else
    {
        cout << "Oh, no problem! Have a good time." << endl;
        return 1;
    }
    int time;
    cout << "what is the time now??";
    cin >> time;
    if (time < 18)
    {
        cout << "good morning. . ." << endl;
    }
    else
    {
        cout << "good evening. . ." << endl;
    }
    cout << "are you at ramdan month?";
    bool ramdan;
    cin >> ramdan;
    if (ramdan)
    {
        cout << "ramdan karim :)" << endl;
    }
    else
    {
        cout << "see you at ramdan. . ." << endl;
    }

    cout << "thank you for this conversation. . .";
    cin.ignore();
    int waiting;
    cin >> waiting;
    if (waiting == 0)
    {
        free;
        return 0;
    }
}
