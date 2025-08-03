#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int whatguess;
    int guess = rand() % 20 + 1; // Ensure the guess is between 1 and 20
    cout << "Welcome to the guessing game!" << endl;
    cout << "I have guessed a number between 1 and 20. Try to guess it!" << endl;

    while (true) {
        cout << "Guess a number from 1 to 20: ";
        cin >> whatguess;

        if (whatguess == guess) {
            cout << "Congratulations!" << endl;
            break;
        } else if (whatguess < 1 || whatguess > 20) {
            cout << "Sir, I said from 1 to 20." << endl;
        } else if (whatguess > guess) {
            cout << "Too high!" << endl;
        } else if (whatguess < guess) {
            cout << "Too low!" << endl;
        }

        cout << "Do you want to exit? (1 for Yes / 0 for No): ";
        cin >> whatguess;
        if (whatguess == 1) {
            break;
        }
    }

    return 0;
}
