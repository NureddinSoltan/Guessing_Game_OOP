#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GuessingGame {
private:
    int secretNumber;
    char secretAlphabet;
    int maxTries;
    int numTries;
    int isLoserNumber;
    int isLoserAlphabet;
    int highScoreNumber;
    int highScoreAlphabet;
    int noOfGuessingNumber;
    int noOfGuessingAlphabet;
    string playerName;

public:
    GuessingGame() {
        secretNumber = 0;
        maxTries = 0;
        numTries = 0;
        highScoreNumber = 0;
        highScoreAlphabet =0;
        playerName = "";
        noOfGuessingNumber =0;
        noOfGuessingAlphabet =0;
        isLoserAlphabet =0;
        isLoserNumber =0;
    }

    void setDifficultyNumber(int level) {
        switch (level) {
            case 1: // Easy
                secretNumber = rand() % 10 + 1;
                cout<<secretNumber<<endl;
                maxTries = 5;
                break;
            case 2: // Medium
                secretNumber = rand() % 25 + 1;
                cout<<secretNumber<<endl;
                maxTries = 4;
                break;
            case 3: // Hard
                secretNumber = rand() % 40 + 1;
                cout<<secretNumber<<endl;
                maxTries = 3;
                break;
            default:
                cout << "Invalid difficulty level!" << endl;
                break;
        }
        numTries = maxTries;
    }
    void playGameNumber() {
        noOfGuessingNumber =0;
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
            cout << "You have " << numTries << " tries left. "<<endl;
            cout << "Chance : #"<< numTries << endl;
            cout << "Enter your guess: " << endl;
            if (!(cin >> guess)) { // Check if input is a number
                cout << "Invalid option!" << endl;
                cin.clear(); // Clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer
                continue;
            }
            if (guess == secretNumber) {
                cout << guess << " Is a correct guess,  congrats amigos ✅" << endl;
                cout << "You win! after "<<numTries <<" Tries 🥳" << endl;
                noOfGuessingNumber++;
                if (noOfGuessingNumber < highScoreNumber || highScoreNumber == 0) {
                    highScoreNumber = noOfGuessingNumber;
                    cout << "New high score for number game: " << highScoreNumber << endl;
                }
                break;
            }
            else if (guess < secretNumber) {
                cout << "Wrong! The secret number Is higher ❌." << endl;
                cout << "Chance : #"<< numTries << endl;
                noOfGuessingNumber++;
                cout << "The number of guessing"  << endl;
            }
            else {
                cout << "Wrong! The secret number Is Lower ❌." << endl;
                cout << "Chance : #"<< numTries << endl;
                noOfGuessingNumber++;
            }
            numTries--;
        }
        if (numTries == 0) {
            cout << "You lose! The secret number was " << secretNumber << "." << endl;
            isLoserNumber = true;
        }
    }
    void NumberGuessing(){
        int choice;
        do {
            cout << "Start Menu :" << endl;
            cout << "-----------" << endl;
            cout << "Select a difficulty level" << endl;
            cout << "1. Easy" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Hard" << endl;
            cout << "4. Return to main menu" << endl;
            cout << "===> ";
            cin >> choice;

            switch (choice) {
                case 1: //Easy
                    setDifficultyNumber(1);
                    playGameNumber();
                    break;
                case 2: //Medium
                    setDifficultyNumber(2);
                    playGameNumber();
                    break;
                case 3: //Hard
                    setDifficultyNumber(3);
                    playGameNumber();
                    break;
                case 4:
                    return ;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                    break;
            }
        } while (true);

    }


    void setDifficultyAlphabet(int level) {
        switch (level) {
            case 1: // Easy
                secretAlphabet = 'A' + rand() % 11;
                cout<<secretAlphabet<<endl;
                maxTries = 5;
                break;
            case 2: // Medium
                secretAlphabet = 'A' + rand() % 17;
                cout<<secretAlphabet<<endl;
                maxTries = 4;
                break;
            case 3: // Hard
                secretAlphabet = 'A' + rand() % 26;
                cout<<secretAlphabet<<endl;
                maxTries = 3;
                break;
            default:
                cout << "Invalid difficulty level!" << endl;
                break;
        }
        numTries = maxTries;
    }
    void playGameAlphabet() {
        noOfGuessingAlphabet =0;
        cout << "Guess an Alphabet between a and ";
        switch (maxTries) {
            case 5:
                cout << "j." << endl;
                break;
            case 4:
                cout << "j." << endl;
                break;
            case 3:
                cout << "z." << endl;
                break;
        }
        while (numTries > 0) {
            char guess;
            cout << "You have " << numTries << " tries left. Enter your guess: ";
            cin >> guess;
            // Convert user guess to uppercase if it's a letter
            if (isalpha(guess)) {
                guess = toupper(guess);
                if (guess == secretAlphabet) {
                    cout << guess << " Is a correct guess,  congrats amigos ✅" << endl;
                    cout << "You win! after "<<numTries <<" Tries 🥳" << endl;
                    noOfGuessingAlphabet++;
                    if (noOfGuessingAlphabet < highScoreAlphabet || highScoreAlphabet == 0) {
                        highScoreAlphabet = noOfGuessingAlphabet;
                        cout << "New high score for alphabet game: " << highScoreAlphabet << endl;
                    }
                    break;
                } else if (guess < secretAlphabet) {
                    cout << "Wrong! The secret alphabet Is higher ❌." << endl;
                    cout << "Chance : #"<< numTries << endl;
                    noOfGuessingAlphabet++;
                } else {
                    cout << "Wrong! The secret alphabet Is Lower ❌." << endl;
                    cout << "Chance : #"<< numTries << endl;
                    noOfGuessingAlphabet++;
                }
                numTries--;
            } else {
                cout << "Invalid option! Please enter a valid alphabet." << endl;
            }
        }
        if (numTries == 0) {
            numTries == isLoserAlphabet;
            cout << "You lose! The secret Alphabet was " << secretAlphabet << "." << endl;
        }
    }
    void AlphabetGuessing() {
            int choice;
        do {
            cout << "Start Menu :" << endl;
            cout << "-----------" << endl;
            cout << "Select a difficulty level" << endl;
            cout << "1. Easy" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Hard" << endl;
            cout << "4. Return to main menu" << endl;
            cout << "===> ";
            cin >> choice;

                switch (choice) {
                    case 1: //Easy
                        setDifficultyAlphabet(1);
                        playGameAlphabet();
                        break;
                    case 2: //Medium
                        setDifficultyAlphabet(2);
                        playGameAlphabet();
                        break;
                    case 3: //Hard
                        setDifficultyAlphabet(3);
                        playGameAlphabet();
                        break;
                    case 4:
                        return ;
                    default:
                        cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                        break;
                }
            } while (true);

        }


    void viewHighScoreNumber(){
        if (noOfGuessingNumber == 0){
            cout << "Guessing Numbers is not played yet" <<endl;
        }
        if (highScoreNumber != 0){
            cout << "Your High Score in Guessing Numbers is: " << highScoreNumber << endl;
        }
        else if (isLoserNumber == true){
            cout<< "You have play Number but you lost, noob, go and sleep loser" <<endl;
            cout<< "*Don't forget to drink milk before sleeping" <<endl;
        }
    }

    void viewHighScoreAlphabet() {
        if(noOfGuessingAlphabet ==0){
            cout << "Guessing Alphabets is not played yet" << endl;
        }
        if (highScoreAlphabet !=0){
            cout << "Your High Score in Guessing Alphabets is: " << highScoreAlphabet << endl;
        }
        else if (isLoserAlphabet == true){
            cout<< "You have play Alphabet but you lost, noob, go and sleep loser." <<endl;
            cout<< "*Don't forget to drink milk before sleeping" <<endl;

        }
    }

    void viewCredits() {
        cout << "This Guessing Game was created by ." << endl;
        cout << "Name : Noureldien Soltan Abdelrahman Ahmed ID : 210209980 Department : SE" << endl;
        cout << "Name : Shiza Khan ID : 200209395 Department : SE" << endl;

    }
};

int main() {
    srand(time(NULL)); // seed for random number generator
    GuessingGame game;
    int choice;
    do {
        cout << "_____________________________________________________________________" << endl;
        cout << "Welcome to ZAN (the best guessing game in the world),play the game :" << endl;
        cout << "-------------------" << endl;
        cout << "Enter 1 for numbers" << endl;
        cout << "Enter 2 for Alphabets" << endl;
        cout << "Enter 3 for getting the high score" << endl;
        cout << "Enter 4 for Credits" << endl;
        cout << "Enter 5 to Exit" << endl;
        cout << "" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1: // Guessing Numbers
                game.NumberGuessing();
                break;
            case 2: // Guessing Alphabets
                game.AlphabetGuessing();
                break;
            case 3: // View High Score
                game.viewHighScoreNumber();
                game.viewHighScoreAlphabet();
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
}
