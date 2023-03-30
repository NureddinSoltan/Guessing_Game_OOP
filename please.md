    #include <iostream>
    #include <ctime>
    #include <cstdlib>
    using namespace std;
    
    int main() {

[//]: # (    int numberHighScore = 0;)
    int alphabetHighScore = 0;
    char playAgain = 'y';
    while (playAgain == 'y') {
    cout << "Do you want to guess a number or an alphabet? (n/a): ";
    char gameType;
    cin >> gameType;
    if (gameType == 'n') {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;

[//]: # (    int tries = 0;)
    int guess;
    do {
    cout << "Enter your guess: ";
    cin >> guess;

[//]: # (    tries++;)
    if (guess < secretNumber) {
    cout << "Your guess is too low." << endl;
    } else if (guess > secretNumber) {
    cout << "Your guess is too high." << endl;
    } else {

    cout << "You got it in " << tries << " tries!" << endl;
    if (tries < numberHighScore || numberHighScore == 0) {
    numberHighScore = tries;
    cout << "New high score for number game: " << numberHighScore << endl;
    }

    }
    } while (guess != secretNumber);
    } else if (gameType == 'a') {
    srand(time(0));
    char secretAlphabet = rand() % 26 + 'a';
    int tries = 0;
    char guess;
    do {
    cout << "Enter your guess: ";
    cin >> guess;
    tries++;
    if (guess < secretAlphabet) {
    cout << "Your guess is too low." << endl;
    } else if (guess > secretAlphabet) {
    cout << "Your guess is too high." << endl;
    } else {
    cout << "You got it in " << tries << " tries!" << endl;
    if (tries < alphabetHighScore || alphabetHighScore == 0) {
    alphabetHighScore = tries;
    cout << "New high score for alphabet game: " << alphabetHighScore << endl;
    }
    }
    } while (guess != secretAlphabet);
    }
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    }
    return 0;
    }