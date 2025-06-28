#include <iostream>
using namespace std;
int main()
{
    string questions[] = {"1.What year was C++ created?: ",
                          "2. Who invented C++?: ",
                          "3.What is the produccessor of C++?:",
                          "4. is the Earth flat?"};
    string options[][4] = {{"A. 1969", "B. 1979", "C. 1985", "D. 1989"},
                           {"A. Guido van Rossum",
                            "B. Bjarne Stroustrup",
                            "C. John Carmack",
                            "D. Mark Zuckerburg"},
                           {"A. C", "B. C+", "C. C--", "D. B++"},
                           {"A. Yes", "B. No", "C. Sometimes", "D. What is Earth?"}};
    char answerKey[] = {'C', 'B', 'A', 'B'};

    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score = 0;

    for (int i = 0; i < size; i++)
    {
        cout << "****************************\n";
        cout << questions[i] << '\n';
        cout << "****************************\n";

        for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++)
        {
            cout << options[i][j] << '\n';
        }
        cout << "choose wisely:";
        cin >> guess;
        guess = toupper(guess);
        if (guess == answerKey[i])
        {
            cout << "CORRECT\n";
            score += 1;
        }
        else
        {
            cout << "WRONG\n";
            cout << "Answer: " << answerKey[i] << '\n';
        }
    }
    cout << "****************************\n";
    cout << "*          RESULTS         *\n";
    cout << "****************************\n";
    cout << "Correct answers: " << score << endl;
    cout << "# of QUETIONS: " << size << endl;
    cout << "Precentege " << (score / (double)size) * 100 << "%" << endl;
    switch (score)
    {
    case 0:
        cout << "PFFFFFF, HAAAAAHAAAAAA" << endl;
    case 1:
        cout << "How you say you are a --real programmer--!!" << endl;
        break;
    case 2:
        cout << "at least you don't fail.." << endl;
        break;
    case 3:
        cout << "interesting.." << endl;
        break;
    case 4:
        cout << "genius a real genuis!!" << endl;
        break;
    default:
        cout << "Hey gaurds.. This kid is cheating!!"; break;
    }
    return 0;
}