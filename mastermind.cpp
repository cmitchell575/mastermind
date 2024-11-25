#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to check user's correct position
int checkUserPosition(string code[], string userGuess[]) {
    int correctPosition = 0; // Local variable to count correct positions
    for (int i = 0; i < 4; i++) {
        if (userGuess[i] == code[i]) {
            correctPosition++;
        }
    }
    return correctPosition; // Return the count of correct positions
}

// Function to check user's correct color
int checkUserColor(string code[], string userGuess[]) {
    int correctColor = 0; // Local variable to count correct colors
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (userGuess[i] == code[j] && i != j) {
                correctColor++;
            }
        }
    }
    return correctColor; // Return the count of correct colors
}

int main() {
    // CONST SETUP
    const int codeLength = 4;
    const int maxAttempts = 10;

    // ARRAY SETUP
    string colors[] = {"Red", "Green", "Blue", "Yellow", "Orange", "Purple"};
    string code[codeLength];
    string userGuess[codeLength];

    // VARIABLE SETUP
    int attempts = 0;

    // SEEDING RNG
    srand(static_cast<unsigned int>(time(0)));

    // GENERATE INITIAL CODE
    for (int i = 0; i < codeLength; i++) {
        code[i] = colors[rand() % 6];
    }
     //INTRO TO GAME
    cout << "This is the game of Mastermind! The Computer has generated a code made up of 4 colors out of 6 available colors!\n" "You have 10 guesses to guess the correct color.\n" "The available colors are Red, Green, Blue, Yellow, Orange, and Purple.\n" "Enter your guess:";

    // START GAME
    while (attempts < maxAttempts) {
   
        // USER GUESS
        for (int i = 0; i < codeLength; i++) {
            cin >> userGuess[i];
        }
        attempts++;

        // CHECK POSITION AND COLOR OF GUESS
        int correctPosition = checkUserPosition(code, userGuess);
        int correctColor = checkUserColor(code, userGuess);

        // CHECK FOR WIN CONDITION
        if (correctPosition == codeLength) {
            cout << "Congratulations! You have guessed the correct color code! You are a Mastermind!" << endl;
        } else {
            cout << "Feedback: " << correctPosition << " correct colors in the correct position, "
                 << correctColor << " correct colors in the wrong position.\n";
        }
    }

    // Check if max attempts reached
    if (attempts >= maxAttempts) {
        cout << "Sorry, you have reached the max attempts, game over! Try again!" << endl;
    }
}