#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GuessingGame {
private:
int secretNumber;
int maxTries;
int numTries;
int highScoreNumber;
string playerName;

public:
GuessingGame() {
secretNumber = 0;
maxTries = 0;
numTries = 0;
highScoreNumber = 0;
playerName = "";
}

    void setDifficulty(int level) {
        switch (level) {
            case 1: // Easy
                secretNumber = rand() % 10 + 1;
                maxTries = 5;
                break;
            case 2: // Medium
                secretNumber = rand() % 25 + 1;
                maxTries = 4;
                break;
            case 3: // Hard
                secretNumber = rand() % 40 + 1;
                maxTries = 3;
                break;
            default:
                cout << "Invalid difficulty level!" << endl;
                break;
        }
        numTries = maxTries;
    }

    void playGame() {
        cout << "Guess a number between 1 and ";
        switch (maxTries) {
            case 5:
                cout << "10." << endl;
                break;
            case 4:
                cout << "25." << endl;
                break;
            case 3:
                cout << "40." << endl;
                break;
        }
        while (numTries > 0) {
            int guess;
            cout << "You have " << numTries << " tries left. Enter your guess: ";
            cin >> guess;
            if (guess == secretNumber) {
                cout << "You win!" << endl;
                if (numTries < highScoreNumber || highScoreNumber == 0) {
                    highScoreNumber = numTries;
                    cout << "New high score: " << highScoreNumber << " tries." << endl;
                }
                break;
            }
            else if (guess < secretNumber) {
                cout << "Wrong! The secret number is higher." << endl;
            }
            else {
                cout << "Wrong! The secret number is lower." << endl;
            }
            numTries--;
        }
        if (numTries == 0) {
            cout << "You lose! The secret number was " << secretNumber << "." << endl;
        }
    }
    void Numberguessing(){
        int choice;
        do {
            cout << "Choose the difiiculty" << endl;
            cout << "1-Easy" << endl;
            cout << "2-Medium" << endl;
            cout << "3-Hard" << endl;
            cout << "4-Retrun to the main menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice;


            switch (choice) {
                case 1: //Easy
                    setDifficulty(1);
                    playGame();
                    break;
                case 2: //Medium
                    setDifficulty(2);
                    playGame();
                    break;
                case 3: //Hard
                    setDifficulty(3);
                    playGame();
                    break;

                case 4: // Exit Game
                    cout << "Thanks for playing!" << endl;
                    return ;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                    break;
            }
        } while (true);

    }
    void AlphabeGuessing(){
        setDifficulty(1);
        playGame();
    }

    void viewHighScore() {
        cout << "High score: " << highScoreNumber << " tries by " << playerName << "." << endl;
    }

    void viewCredits() {
        cout << "This Guessing Game was created by ChatGPT." << endl;
    }

    void setPlayerName(string name) {
        playerName = name;
    }
};

int main() {
srand(time(NULL)); // seed for random number generator
GuessingGame game;
int choice;
do {
cout << "-------------------" << endl;
cout << "Guessing Game Menu" << endl;
cout << "-------------------" << endl;
cout << "1. Play Guessing Numbers" << endl;
cout << "2. Play Guessing Alphabets" << endl;
cout << "3. View High Score" << endl;
cout << "4. View Credits" << endl;
cout << "5. Exit Game" << endl;
cout << "Enter your choice: ";
cin >> choice;


        switch (choice) {
            case 1: // Guessing Numbers
                game.Numberguessing();
                break;
            case 2: // Guessing Alphabets
                game.AlphabeGuessing();
                break;
            case 3: // View High Score
                game.viewHighScore();
                break;
            case 4: // View Credits
                game.viewCredits();
                break;
            case 5: // Exit Game
                cout << "Thanks for playing!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    } while (true);

    return 0;
}

