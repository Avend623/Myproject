// *       ( 1#2#3 )
// *       ( 4#5#6 )
// *       ( 4#5#6 )
// int num 1-9
// PvE
// P will chose O and else
// if he chose num this num will be locked
// if the player pick num 1 5 9 or 3 5 7 or 1 2 3 or 4 5 6 or 7 8 9 or 1 4 7 or 2 5 8 or 3 6 9 he will win same thing for computer
// none of them is tie
#include<time.h>
#include<random>
#include <iostream>
using namespace std;
int main()
{
    int num;
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "( 1#2#3 )\n( 4#5#6 )\n( 7#8#9 )";
    cout << "choose a number:";
    cin >> num;
    if (num > 0 && num < 10)
    {
    }
    else
    {
        cout << "wrong num!" << endl;
        cout << "please choose again:";
        cin >> num;
    }
    cout<<endl;
    switch (num)
    {
    case 1:
        cout << "( O#2#3 )\n( 4#5#6 )\n( 7#8#9 )";
        break;
    case 2:
        cout << "( 1#O#3 )\n( 4#5#6 )\n( 7#8#9 )";
        break;
    case 3:
        cout << "( 1#2#O )\n( 4#5#6 )\n( 7#8#9 )";
        break;
    case 4:
        cout << "( 1#2#3 )\n( O#5#6 )\n( 7#8#9 )";
        break;
    case 5:
        cout << "( 1#2#3 )\n( 4#O#6 )\n( 7#8#9 )";
        break;
    case 6:
        cout << "( 1#2#3 )\n( 4#5#O )\n( 7#8#9 )";
        break;
    case 7:
        cout << "( 1#2#3 )\n( 4#5#6 )\n( O#8#9 )";
        break;
    case 8:
        cout << "( 1#2#3 )\n( 4#5#6 )\n( 7#O#9 )";
        break;
    case 9:
        cout << "( 1#2#3 )\n( 4#5#6 )\n( 4#5#O )";
        break;

    default:
        break;
    }
    srand(time(0));
    switch (rand() % 10)
    {
    case 1:
        cout << "( X#2#3 )\n( 4#5#6 )\n( 7#8#9 )";
        break;
    case 2:
        cout << "( 1#X#3 )\n( X#5#6 )\n( 7#8#9 )";
        break;
    case 3:
        cout << "( 1#2#X )\n( 4#X#6 )\n( 7#8#9 )";
        break;
    case 4:
        cout << "( 1#2#3 )\n( X#5#6 )\n( 7#8#9 )";
        break;
    case 5:
        cout << "( 1#2#3 )\n( 4#X#6 )\n( X#8#9 )";
        break;
    case 6:
        cout << "( 1#2#3 )\n( 4#5#X )\n( 7#X#9 )";
        break;
    case 7:
        cout << "( 1#2#3 )\n( 4#5#6 )\n( X#8#9 )";
        break;
    case 8:
        cout << "( 1#2#3 )\n( 4#5#6 )\n( 7#X#9 )";
        break;
    case 9:
        cout << "( 1#2#3 )\n( 4#5#6 )\n( 4#5#X )";
        break;

    default:
        break;
    }
    return 0;
}