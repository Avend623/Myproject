#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;
void ClearScreen()
{
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}
// Change console text color
void countdown()
{
    for (int i = 3; i > 0; i--)
    {
        cout<<"The game start in "<<i<<"...";
        Sleep(900);
        ClearScreen();
    }
}
void SetColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
static int player_N = 0;
void instructions();
class Snake
{
private:
    enum edirection
    {
        Stop,
        Top,
        Down,
        Right,
        Left
    };
    edirection dir;
    int width, height, x, y, fruitX, fruitY, Tail_N = 0, score = 0, burn = 0, TailX[100], TailY[100];
    bool GameOver = false;
    string name;

public:
    int Setup(int Width);
    void Draw();
    void Input();
    bool Gamover() { return GameOver; }
    int Get_Score() { return score; }
    string Get_Name() { return name; }
    void Logic();
    void Generate_fruit();
    void Shift_Right(int arr[], int size);
};

void Snake::Shift_Right(int arr[], int size)
{
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
}

void Snake::Generate_fruit()
{
    bool wh;
    do
    {
        wh = false;
        fruitX = (rand() % (width - 2)) + 1;
        fruitY = (rand() % (height - 2)) + 1;
        for (int i = 0; i < Tail_N; i++)
        {
            if ((fruitX == TailX[i] && fruitY == TailY[i]) || (fruitX == x && fruitY == y))
            {
                wh = true;
                break; // Exit the loop early if a match is found
            }
        }
    } while (wh);
}

int Snake::Setup(int Width)
{
    if (burn == 1)
        return 0;
    srand(time(NULL));
    dir = Stop;
    cout << "enter player name:";
    cin >> name;
    player_N++;
    width = Width;
    height = width / 2;
    x = width / 2;
    y = height / 2;
    burn++;
    Generate_fruit();
    countdown();
}
void Snake::Draw()
{
    ClearScreen();
    cout << "PLayer " << player_N << " :" << name << endl;
    cout << "PLayer's Score:" << score << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1)
                cout << "*";
            else if (j == 0 || j == width - 1)
                cout << "*";
            // In Draw()
            else if (i == y && j == x)
            {
                SetColor(2); // Green for snake
                cout << "O";
                SetColor(7); // Reset to white
            }
            else if (i == fruitY && j == fruitX)
            {
                SetColor(12); // Red for fruit
                cout << "$";
                SetColor(7); // Reset to white
            }

            else
            {
                bool printed = false;
                for (int z = 0; z < Tail_N; z++)
                {
                    if (TailX[z] == j && TailY[z] == i)
                    {
                        SetColor(10); // Bright green tail
                        cout << "o";
                        printed = true;
                        SetColor(7); // Reset to white
                        break;
                    }
                }
                if (!printed)
                    cout << " ";
            }
        }
        cout << endl;
    }
}
void Snake::Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = Top;
            break;
        case 'a':
            dir = Left;
            break;
        case 's':
            dir = Down;
            break;
        case 'd':
            dir = Right;
            break;
        case 'x':
            GameOver = true;
            break;
        }
    }
}
void Snake::Logic()
{
    Shift_Right(TailX, 100);
    Shift_Right(TailY, 100);
    TailX[0] = x;
    TailY[0] = y;
    switch (dir)
    {
    case Top:
        y--;
        break;
    case Down:
        y++;
        break;
    case Right:
        x++;
        break;
    case Left:
        x--;
        break;
    }
    if (x == fruitX && y == fruitY)
    {
        Generate_fruit();
        Tail_N++;
        score++;
        Beep(750, 100); // Beep sound when fruit is eaten
    }
    if (x == 0 || x >= width - 1 || y == 0 || y >= height - 1)
    {
        GameOver = true;
        Beep(500, 200); // Beep sound when game is over
        Beep(700, 200); // Beep sound when game is over
        Beep(900, 200); // Beep sound when game is over
    }
    for (int i = 0; i < Tail_N; i++)
    {
        if (x == TailX[i] && y == TailY[i])
        {
            GameOver = true;
            Beep(500, 200); // Beep sound when game is over
            Beep(700, 200); // Beep sound when game is over
            Beep(900, 200); // Beep sound when game is over
        }
    }
}
void Results(Snake obs[], int size);
int main()
{
    // PlaySound(TEXT("651670__code_box__desert-snake.wav"), NULL, SND_FILENAME | SND_ASYNC);
    instructions();
    int size;
    int width; // Declare width variable
    cout << "Enter your Map width(minimum 20):";
    cin >> width;
    while (width < 20)
    {
        cout << "too small!" << endl;
        cout << "Enter your Map width(minimum 20):";
        cin >> width;
    }

    cout << "Number of Players: ";
    cin >> size;
    Snake *obs = new Snake[size];
    for (int i = 0; i < size; i++)
    {
        while (!obs[i].Gamover())
        {
            obs[i].Setup(width);
            obs[i].Draw();
            obs[i].Input();
            obs[i].Logic();
            Sleep(100);
        }
    }
    Results(obs, size);
    delete[] obs;
    system("pause");
}
void Results(Snake obs[], int size)
{
    bool ITW = 0;
    int Twinner = 1;
    int type = 0;
    string winner;

    int highestScore = obs[0].Get_Score();
    winner = obs[0].Get_Name();

    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            break;
        if (obs[i].Get_Score() < obs[i + 1].Get_Score())
        {
            highestScore = obs[i + 1].Get_Score();
            winner = obs[i + 1].Get_Name();
            type = 0;
        }
    }
    if (type == 0)
    {
        cout << "The Winner is " << winner << endl;
        cout << "The Score is " << highestScore << endl;
    }
    else
    {
        cout << "No winner" << endl;
        cout << "TIE!!" << endl;
    }
    cout << "" << endl;
    cout << "General Scores:" << endl;
    for (int i = 0; i < size; i++)
    {
        if (obs[i].Get_Score() == highestScore)
        {
            cout << "THE WINNER, PLAYER " << i + 1 << ":" << obs[i].Get_Name() << endl;
            cout << "THE WINNER, PLAYER " << i + 1 << "'s SCORE:" << obs[i].Get_Score() << endl;
        }
        else
        {
            cout << "PLAYER " << i + 1 << ":" << obs[i].Get_Name() << endl;
            cout << "PLAYER " << i + 1 << "'s SCORE:" << obs[i].Get_Score() << endl;
        }
    }
}
void instructions()
{
    SetColor(4);
    cout << "*The height will be half of width" << endl;
    getch();
        cout << "Use WASD to move the snake" << endl;
    getch();
        cout << "The highest score will win." << endl;
    getch();
        cout << "Please,Respect my game." << endl;
    getch();
    cout << "Enjoy.." << endl;
    SetColor(7);
    Sleep(200);
}
