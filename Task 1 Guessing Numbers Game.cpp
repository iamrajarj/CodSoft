//Sachal Raja Task 1
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    int lowerBound = 1, upperBound = 100, guess, attempts = 0; 
    // Generating a random number
    int secretNumber = rand() % (upperBound + 1);

    cout << "\t\tWelcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between " << lowerBound << " and " << upperBound << "." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) 
            cout << "Too low! Try again." << endl;
        else if (guess > secretNumber)
            cout << "Too high! Try again." << endl;
        else
            cout << "Congratulations! You've guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
    } while (guess != secretNumber);

    return 0;
}
