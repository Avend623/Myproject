#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h> // Include mmsystem.h for PlaySound
using namespace std;
void Shift_Right(int arr[], int size) // [1,2,3,4,5,6,7,8,9,10]
{
    for (int i = size - 2; i >= 0; i--)
        arr[i + 1] = arr[i];
}
// -----------------Properities------------------
enum Direction
{
    TOP = 1,
    DOWN,
    RIGHT,
    LEFT
};
struct Map
{
    int width, height, fruitX, fruitY;
};
struct Snake
{
    int HeadX, HeadY, Tail_N;
    int TailX[100], TailY[100];
    Direction Dir;
};
struct Player
{
    int score;
    bool lose;
};
// ----------------------------------------------
Map Map1;
Snake Snake1;
Player Player1;
void Generate_fruit()
{
    srand(time(NULL));
    Map1.fruitX = rand() % (Map1.width - 2) + 1;  //* 1 to 38
    Map1.fruitY = rand() % (Map1.height - 2) + 1; //* 1 to 38
}
void Setup()
{
    Map1.width = 40;
    Map1.height = 20;
    Generate_fruit();
    // -----------------------------
    Snake1.HeadX = Map1.width / 2;
    Snake1.HeadY = Map1.height / 2;
    Snake1.Tail_N = 0;
    // -----------------------------
    Player1.score = 0;
    Player1.lose = false;
}
void Drow()
{
    system("cls");
    for (int i = 0; i < Map1.height; i++)
    {
        for (int j = 0; j < Map1.width; j++)
        {
            if (i == 0 || i == Map1.height - 1)
                cout << "*";
            else if (j == 0 || j == Map1.width - 1)
                cout << "*";
            else if (i == Snake1.HeadY && j == Snake1.HeadX)
                cout << "O";
            else if (i == Map1.fruitY && j == Map1.fruitX)
                cout << "$";
            else
            {
                bool printed = false;
                for (int z = 0; z < Snake1.Tail_N; z++)
                {
                    if (Snake1.TailX[z] == j && Snake1.TailY[z] == i)
                    {
                        cout << "o";
                        printed = true;
                        break;
                    }
                }
                if (!printed)
                    cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Player Score : " << Player1.score << endl;
}
void Input()
{
    if (_kbhit())
    {
        char c = _getch();
        switch (c)
        {
        case 'w':
            Snake1.Dir = TOP;
            break;
        case 'a':
            Snake1.Dir = LEFT;
            break;
        case 's':
            Snake1.Dir = DOWN;
            break;
        case 'd':
            Snake1.Dir = RIGHT;
            break;
        case 'x':
            Player1.lose = true;
        }
    }
}
void Move()
{
    Shift_Right(Snake1.TailX, 100); // o o o o o o
    Shift_Right(Snake1.TailY, 100); // o O
    Snake1.TailY[0] = Snake1.HeadY;
    Snake1.TailX[0] = Snake1.HeadX;
    switch (Snake1.Dir)
    {
    case TOP:
        Snake1.HeadY--;
        break;
    case DOWN:
        Snake1.HeadY++;
        break;
    case RIGHT:
        Snake1.HeadX++;
        break;
    case LEFT:
        Snake1.HeadX--;
        break;
    }
    if (Snake1.HeadY >= Map1.height - 1 || Snake1.HeadY <= 0 || Snake1.HeadX >= Map1.width - 1 || Snake1.HeadX <= 0)
    {
        Player1.lose = true;
        Beep(500, 500); // Beep sound when game is over
        PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC); // Play game over sound
    }
    if (Snake1.HeadY == Map1.fruitY && Snake1.HeadX == Map1.fruitX)
    {
        Generate_fruit();
        Player1.score++;
        Snake1.Tail_N++;
        Beep(750, 300); // Beep sound when fruit is eaten
        PlaySound(TEXT("eat.wav"), NULL, SND_FILENAME | SND_ASYNC); // Play eat sound
    }
    for (int i = 0; i < Snake1.Tail_N; i++)
    {
        if (Snake1.HeadX == Snake1.TailX[i] && Snake1.HeadY == Snake1.TailY[i])
        {
            Player1.lose = true;
            Beep(500, 500); // Beep sound when game is over
            PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC); // Play game over sound
        }
    }
}
int main()
{
    PlaySound(TEXT("background.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); // Play background music
    Setup();
    while (!Player1.lose)
    {
        Drow();
        Input();
        Move();
        Sleep(50);
    }
    cout<<"[GameOVER!]"<<endl;
    system("pause");
}