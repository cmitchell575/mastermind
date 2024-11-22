#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Functions
void generateCode (string code[], int codeLength);
void getUserGuess (string userGuess[], int codeLength);
void feedback (const string code[], const string userGuess[], int codeLength);

int main() {
  const int codeLength = 4; // Length of the code
  const int maxAttempts = 10; // Max # of attempts
  string code[codeLength]; // Array to hold the code
  string userGuess[codeLength]; // Array to hold the user's guess
  int attempts = 0; // Variable to count the number of attempts

// Seed the random generator
srand(static_cast<unsigned int>(time(0)));

// Generate the code
generateCode(code, codeLength);
cout << "Welcome to Mastermind!\n";
cout << "Try to guess the secret code consisting of " << codeLength << " colors.\n";
cout << "Available colors: Red, Green, Blue, yellow, Orange, Purple\n";

//Main game loop
while (attempts < maxAttempts){
  //Get the user's guess
  getUserGuess(userGuess, codeLength);
  attempts++;
  //Provide feedback on the user's guess
  feedback (code, userGuess, codeLength);
  //Check if the user has guessed the code correctly
  if (userGuess[0] == code[0] && userGuess[1] == code[1] && userGuess[2] == code[2] && userGuess[3] == code[3]) {
    cout << "Congratulations! You've guessed the secret code!\n";
    break;
  } else if (attempts == maxAttempts){
    cout << "Sorry, you've used all your attempts. The secret code was: ";
    for (int i = 0; i < codeLength; i++) {
      cout << code[i] << " ";
    }
    cout << "\n";
  }
}
return 0;
}

//Function to generate a random code
void generateCode(string code[], int codeLength) {
  string colors[] = {"Red", "Green", "Blue", "Yellow", "Orange", "Purple"};
  for (int i=0; i < codeLength; i++) {
    code[i] = colors[rand() % 6]; // Randomly select a color
  }
}

//Function to get the user's guess
void getUserGuess(string userGuess[], int codeLength){
  cout << "Enter your guess (4 colors): ";
  for (int i = 0; i < codeLength; i++) {
      cin >> userGuess[i]; //Store the user's guess
  }
}

//Function to provide feedback on the user's guess
void feedback(const string code[], const string userGuess[], int codeLength){
  int correctPosition = 0;
  int correctColor = 0;
  for (int i = 0; i < codeLength; i++) {
    if (userGuess[i] == code[i]) {
        correctPosition++;
    }
  }
  for (int i = 0; i < codeLength; i++) {
    for (int j = 0; j < codeLength; j++) {
      if (userGuess[i] == code[j] && i != j) {
        correctColor++;
      }
    }
  }
//Provide the feedback to the user
cout << "Feedback: " << correctPosition << " correct colors in the correct position, " << correctColor << " correct colors in the wrong position.\n";
}
