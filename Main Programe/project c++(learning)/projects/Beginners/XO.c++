#include <iostream>
using namespace std;
char Player = 'X';
char Map[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void Draw()
{
    cout << "  -----------\n";
    system("cls");
    for (int r = 0; r < 3; r++)
    {
        cout << " | ";
        for (int c = 0; c < 3; c++)
        {
            cout << " " << Map[r][c] << " ";
        }
        cout << " | \n";
    }
    cout << "  -----------\n";
}
void Replace()
{
    bool validmove = false;
    char pos;
    cout << "Enter your postition(" << Player << "):";
    cin >> pos;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (Map[r][c] == pos)
            {
                Map[r][c] = Player;
                validmove = true;
            }
        }
    }
    if (!validmove)
    {
        cout << "Invalid move! Try again." << endl;
        Replace();
    }
    else
        Player = (Player == 'O') ? 'X' : 'O';
}
char GameOver()
{
    for (int i = 0; i < 3; i++)
    {
        if (Map[0][i] == Map[1][i] && Map[1][i] == Map[2][i]) //* Columns checker
        {
            return Map[0][i];
        }
        if (Map[i][0] == Map[i][1] && Map[i][1] == Map[i][2]) //* Rows checker
        {
            return Map[i][0];
        }
    }
    if (Map[0][0] == Map[1][1] && Map[1][1] == Map[2][2])
    {
        return Map[0][0];
    }
    if (Map[0][2] == Map[1][1] && Map[1][1] == Map[2][0])
    {
        return Map[0][2];
    }
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (Map[r][c] != 'O' && Map[r][c] != 'X')
            {
                return '*';
            }
        }
    }
    return '=';
}
int main()
{
    char result;
    while ((result = GameOver()) == '*')
    {
        Draw();
        Replace();
    }
    Draw();
    if (result == 'O')
        cout<<"O is the winner!"<<endl;
    else if(result == 'X')
        cout<<"X is the winner!"<<endl;
    else
        cout<<"Tie!"<<endl;
    cout<<"[Programme Finished]"<<endl;
    system("pause");
}