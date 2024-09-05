#include <iostream>
using namespace std;
char Matrix[3][3] = {{'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'}};
char Player = 'X';
int Drow()
{
    cout << "-----------\n";
    for (int r = 0; r < 3; r++)
    {
        cout << "|";
        for (int c = 0; c < 3; c++)
        {
            cout << " " << Matrix[r][c] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << "-----------\n";
}
int Replace()
{
    char pos;
    cout << "Enter your position(" << Player << "):";
    cin >> pos;
    system("cls");
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (Matrix[r][c] == pos)
                Matrix[r][c] = Player;
        }
    }
    if (Player == 'X')
        Player = 'O';
    else
        Player = 'X';
}
char CheckWinner()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if (Matrix[i][0] == Matrix[i][1] && Matrix[i][1] == Matrix[i][2])
            return Matrix[i][0];
        if (Matrix[0][i] == Matrix[1][i] && Matrix[1][i] == Matrix[2][i])
            return Matrix[0][i];
    }

    // Check diagonals
    if (Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2])
        return Matrix[0][0];
    if (Matrix[0][2] == Matrix[1][1] && Matrix[1][1] == Matrix[2][0])
        return Matrix[0][2];

    // Check for draw
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (Matrix[r][c] != 'X' && Matrix[r][c] != 'O')
                return '*'; // Game is still ongoing
        }
    }

    return '='; // Draw
}
int main()
{
    while (CheckWinner() == '*')
    {
        Drow();
        Replace();
    }
        if (CheckWinner() == 'O')
        {
            cout << "O is the winner!" << endl;
            Drow();
        }
        else if (CheckWinner() == 'X')
        {
            cout << "X is the winner!" << endl;
            Drow();
        }
        else
        {
            cout<<"Tie"<<endl;
        }
    cout << "[Programme Finished]";
    return 0;
}