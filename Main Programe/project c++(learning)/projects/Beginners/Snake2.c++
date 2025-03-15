#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;

// Function to clear the console screen
void ClearScreen()
{
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    // Get the console screen buffer info
    GetConsoleScreenBufferInfo(console, &screen);
    // Fill the console output with spaces to clear it
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    // Reset the console text attributes
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    // Set the cursor position to the top left
    SetConsoleCursorPosition(console, topLeft);
}

// Function to display a countdown before the game starts
void countdown()
{
    for (int i = 3; i > 0; i--)
    {
        cout << "The game starts in " << i << "...";
        Beep(1000, 200); // Beep sound for countdown
        Sleep(600); // Shorten the countdown duration
        ClearScreen();
    }
    Beep(1500, 300); // Beep sound when countdown ends
}

// Function to set the console text color
void SetColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

static int player_N = 0; // Static variable to keep track of player number

void instructions(); // Function prototype for displaying instructions

// Snake class definition
class Snake
{
private:
    enum edirection { Stop, Top, Down, Right, Left }; // Enumeration for direction
    edirection dir; // Current direction of the snake
    int width, height, x, y, fruitX, fruitY, Tail_N = 0, score = 0, burn = 0, TailX[100], TailY[100];
    bool GameOver = false;
    string name;

public:
    int Setup(int Width); // Function to set up the game
    void Draw(); // Function to draw the game
    void Input(); // Function to handle user input
    bool Gamover() { return GameOver; } // Function to check if the game is over
    int Get_Score() { return score; } // Function to get the score
    string Get_Name() { return name; } // Function to get the player's name
    void Logic(); // Function to handle game logic
    void Generate_fruit(); // Function to generate a new fruit
    void Shift_Right(int arr[], int size); // Function to shift the tail array to the right
};

// Function to shift the tail array to the right
void Snake::Shift_Right(int arr[], int size)
{
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
}

// Function to generate a new fruit
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

// Function to set up the game
int Snake::Setup(int Width)
{
    if (burn == 1)
        return 0;
    srand(time(NULL)); // Seed the random number generator
    dir = Stop; // Initialize direction to Stop
    cout << "enter player name:";
    cin >> name;
    player_N++;
    width = Width;
    height = width / 2;
    x = width / 2;
    y = height / 2;
    burn++;
    Generate_fruit(); // Generate the first fruit
    countdown(); // Display the countdown
}

// Function to draw the game
void Snake::Draw()
{
    ClearScreen(); // Clear the screen
    cout << "PLayer " << player_N << " :" << name << endl;
    cout << "PLayer's Score:" << score << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1)
                cout << "*"; // Draw the top and bottom borders
            else if (j == 0 || j == width - 1)
                cout << "*"; // Draw the left and right borders
            else if (i == y && j == x)
            {
                SetColor(2); // Green for snake
                cout << "O"; // Draw the snake's head
                SetColor(7); // Reset to white
            }
            else if (i == fruitY && j == fruitX)
            {
                SetColor(12); // Red for fruit
                cout << "$"; // Draw the fruit
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
                        cout << "o"; // Draw the snake's tail
                        printed = true;
                        SetColor(7); // Reset to white
                        break;
                    }
                }
                if (!printed)
                    cout << " "; // Draw empty space
            }
        }
        cout << endl;
    }
}

// Function to handle user input
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

// Function to handle game logic
void Snake::Logic()
{
    Shift_Right(TailX, 100); // Shift the tail arrays to the right
    Shift_Right(TailY, 100);
    TailX[0] = x; // Update the head position in the tail arrays
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
        Generate_fruit(); // Generate a new fruit
        Tail_N++; // Increase the tail length
        score++; // Increase the score
        Beep(750, 50); // Beep sound when fruit is eaten
    }
    if (x == 0 || x >= width - 1 || y == 0 || y >= height - 1)
    {
        GameOver = true;
        Beep(500, 200); // Lower frequency for game over
        Beep(400, 200); // Lower frequency for game over
        Beep(300, 200); // Lower frequency for game over
    }
    for (int i = 0; i < Tail_N; i++)
    {
        if (x == TailX[i] && y == TailY[i])
        {
            GameOver = true;
            Beep(500, 200); // Lower frequency for game over
            Beep(400, 200); // Lower frequency for game over
            Beep(300, 200); // Lower frequency for game over
        }
    }
}

// Function to display the results
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
            SetColor(10);
            cout << "THE WINNER, PLAYER " << i + 1 << ":" << obs[i].Get_Name() << endl;
            cout << "THE WINNER, PLAYER " << i + 1 << "'s SCORE:" << obs[i].Get_Score() << endl;
            SetColor(7);
        }
        else
        {
            SetColor(12);
            cout << "PLAYER " << i + 1 << ":" << obs[i].Get_Name() << endl;
            cout << "PLAYER " << i + 1 << "'s SCORE:" << obs[i].Get_Score() << endl;
            SetColor(7);
        }
    }
}

// Function to display instructions
void instructions()
{
    SetColor(4);
    cout << "*The height will be half of width" << endl;
    Beep(1000, 200); // Beep sound for instruction
    getch();
    cout << "Use WASD to move the snake" << endl;
    Beep(1000, 200); // Beep sound for instruction
    getch();
    cout << "The highest score will win." << endl;
    Beep(1000, 200); // Beep sound for instruction
    getch();
    cout << "Please, Respect my game." << endl;
    Beep(1000, 200); // Beep sound for instruction
    getch();
    cout << "Enjoy.." << endl;
    SetColor(7);
    Sleep(200);
}

// Main function
int main()
{
    // PlaySound(TEXT("651670__code_box__desert-snake.wav"), NULL, SND_FILENAME | SND_ASYNC);
    instructions(); // Display instructions
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
    Snake *obs = new Snake[size]; // Create an array of Snake objects
    for (int i = 0; i < size; i++)
    {
        while (!obs[i].Gamover())
        {
            obs[i].Setup(width); // Set up the game
            obs[i].Draw(); // Draw the game
            obs[i].Input(); // Handle user input
            obs[i].Logic(); // Handle game logic
            Sleep(100); // Delay for a short period
        }
        system("pause");
    }
    Results(obs, size); // Display the results
    delete[] obs; // Delete the array of Snake objects
    system("pause"); // Pause the system
}
