#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
    /**
    GuessingGame{}
    This is a class named GuessingGame(), which the main class of this game.
    It has several fields, and methods.
    */
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
    bool isHint;

public:
    GuessingGame() {
        secretNumber = 0;
        maxTries = 0;
        numTries = 0;
        highScoreNumber = 0;
        highScoreAlphabet =0;
        noOfGuessingNumber =0;
        noOfGuessingAlphabet =0;
        isLoserAlphabet =0;
        isLoserNumber =0;
    }

    /**
    setDifficultyNumber()
    Sets the bound for the random numbers generation.
    generates a random number between 1 and the upper bound using
    the 'NumberGuessing' class.
    @param level can be a number (15,25,40)
    */
    void setDifficultyNumber(int level) {
        switch (level) {
            case 1: // Easy
                secretNumber = rand() % 15 + 1;
                cout<<secretNumber<<endl;//🚀
                maxTries = 5;
                break;
            case 2: // Medium
                secretNumber = rand() % 25 + 1;
                cout<<secretNumber<<endl;//🚀
                maxTries = 4;
                break;
            case 3: // Hard
                secretNumber = rand() % 40 + 1;
                cout<<secretNumber<<endl; //🚀
                maxTries = 3;
                break;
            default:
                cout << "Invalid difficulty level!" << endl;
                break;
        }
        numTries = maxTries;
    }

    /**
    playGameNumber()
    Sets the bound for the random numbers generation.
    It checks if the user's input matches the randomNumber variable, and if so,
    prints a message to the console indicating that the user won.
    If the user's input is higher than the randomNumber, it decreases the number
    of guesses remaining and prints a message indicating that the secret number is higher or
    the secret number is low and if there is a hint it will display this.
    if the user enter something rather than the number it will display "Invalid option!"
    */
    void playGameNumber() {
        noOfGuessingNumber =0;
        cout << "Guess a number from 1 to ";
        switch (maxTries) {
            case 5:
                cout << "15.  ";
                break;
            case 4:
                cout << "25.  ";
                break;
            case 3:
                cout << "40.  ";
                break;
        }
        cout << numTries << " Chances left "<<endl;
        while (numTries > 0) {
            int guess;
            cout << "Chance : #"<< numTries << endl;
            cout << "Enter your guess: ";
            if (!(cin >> guess)) { // Check if input is a number
                cout << "Invalid option! Please enter a valid number." << endl;
                cin.clear(); // Clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer
                continue;
            }
            if (guess == secretNumber) {
                cout << guess << " Is a correct guess, congrats amigos \U00002705" << endl;
                cout << "You win! after "<<numTries <<" Tries \U0001F973" << endl;
                noOfGuessingNumber++;
                if (noOfGuessingNumber < highScoreNumber || highScoreNumber == 0) {
                    highScoreNumber = noOfGuessingNumber;
                    cout << "New high score for Numbers Game:" << "("<< highScoreNumber <<")\U0001F3C1"<< endl;
                }
                cout << ""<< endl;
                break;
            }
            else if (guess < secretNumber) {
                if (isHint) {
                    cout << "WRONG! The secret number is higher \U0000274C." << endl;
                }
                noOfGuessingNumber++;
            }
            else {
                if (isHint) {
                    cout << "WRONG! The secret number is Lower \U0000274C." << endl;
                }
                noOfGuessingNumber++;
            }
            numTries--;
        }
        if (numTries == 0) {
            cout << "You lost! The secret number was " << secretNumber << "\U0001F979" << endl;
            cout << ""<< endl;
            isLoserNumber = true;
        }
    }

    /**
    NumberGuessing()
    display the start menu, sets the game parameters for level.
    hint availability, and the upper bound of the range.
    It then prints game instructions to the console, and
    include the playGameNumber() method
    */
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
                    Instructions("Numbers","NUMBER", 5,"Easy");
                    isHint = true;
                    playGameNumber();
                    break;
                case 2: //Medium
                    setDifficultyNumber(2);
                    Instructions("Numbers","NUMBER", 4,"Medium");
                    isHint = false;
                    playGameNumber();
                    break;
                case 3: //Hard
                    setDifficultyNumber(3);
                    Instructions("Numbers","NUMBER", 3,"Hard");
                    isHint = false;
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

    /**
    setDifficultyAlphabet()
    Sets the bound for the random Alphabet generation.
    generates a random alphabet between 1 and the upper bound using
    the 'AlphabetGuessing' class.
    @param level can be a number (j,q,z)
    */
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

    /**
    playGameAlphabet()
    Sets the bound for the random Alphabet generation.
    It checks if the user's input matches the randomAlphabet variable, and if so,
    prints a message to the console indicating that the user won.
    If the user's input is higher than the randomAlphabet, it decreases the number
    of guesses remaining and prints a message indicating that the secret alphabet is higher or
    the secret alphabet is low and if there is a hint it will display this.
    if the user enter something rather than the alphabet it will display "Invalid option!"
    */
    void playGameAlphabet() {
        noOfGuessingAlphabet =0;
        cout << "Guess an Alphabet from 'a' to ";
        switch (maxTries) {
            case 5:
                cout << "'j'. ";
                break;
            case 4:
                cout << "'q'. ";
                break;
            case 3:
                cout << "'z'. ";
                break;
        }
        cout << numTries << " Chances left "<<endl;
        while (numTries > 0) {
            char guess;
            cout << "Chance : #"<< numTries << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            // Convert user guess to uppercase if it's a letter
            if (isalpha(guess)) {
                guess = toupper(guess);
                if (guess == secretAlphabet) {
                    cout << guess << " is a correct guess,  congrats amigos \U00002705" << endl;
                    cout << "You win! after "<<numTries <<" Tries \U0001F973" << endl;
                    noOfGuessingAlphabet++;
                    if (noOfGuessingAlphabet < highScoreAlphabet || highScoreAlphabet == 0) {
                        highScoreAlphabet = noOfGuessingAlphabet;
                        cout << "New high score for Alphabets Game: " << "("<< highScoreAlphabet <<")\U0001F3C1"<< endl;
                    }
                    cout << ""<< endl;
                    break;
                }
                else if (guess < secretAlphabet) {
                    if (isHint) {
                        cout << "WRONG! The secret alphabet is higher \U0000274C." << endl;
                    }
                    noOfGuessingAlphabet++;
                } else {
                    if (isHint) {
                        cout << "WRONG! The secret alphabet is Lower \U0000274C." << endl;
                    }
                    noOfGuessingAlphabet++;
                }
                numTries--;
            } else {
                cout << "Invalid option! Please enter a valid alphabet." << endl;
            }
        }
        if (numTries == 0) {
            cout << "You lost! The secret Alphabet was " << secretAlphabet << "\U0001F979" << endl;
            cout << ""<< endl;
            isLoserAlphabet = true;

        }
    }

    /**
    AlphabetGuessing()
    display the start menu, sets the game parameters for level.
    hint availability, and the upper bound of the range.
    It then prints game instructions to the console, and
    include the playGameAlphabet() method
    */
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
                        Instructions("Alphabets","ALPHABET", 5,"Easy");
                        isHint = true;
                        playGameAlphabet();
                        break;
                    case 2: //Medium
                        setDifficultyAlphabet(2);
                        Instructions("Alphabets","ALPHABET", 4,"Medium");
                        isHint = false;
                        playGameAlphabet();
                        break;
                    case 3: //Hard
                        setDifficultyAlphabet(3);
                        Instructions("Alphabets","ALPHABET", 3,"Hard");
                        isHint = false;
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

    /**
    Instructions()
    creates a message that gives instructions to the player about how to play the
    game.
    @param type    can be String (Numbers, Alphabets)
    @param type1    can be String (Number, Alphabet)
    @param chances can be an integer from (5, 4, 3)
    @param level   can be a String (easy, medium, hard)
    **/
    void Instructions(string type,string type1, int chances, string level) {
        cout<< R"(
Guess the )" + type + R"( :
------------------------------------------
Instructions:
1. Guess the )" + type + R"( based on the given range.
2. You are allowed to make one guess at a time.
3. Each game has )" + to_string(chances) + R"( chances to guess the SECRET )"+ type1 + R"(.
4. Once you have used all your chances, you lose the game.

Good Luck!
)" + level + R"( :
)";}

    /**
    viewHighScoreNumber()
    A function to get report of highScore for each model game,
    and prints a message in number.
    */
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

    /**
    viewHighScoreAlphabet()
    A function to get report of highScore for each model game,
    and prints a message in alphabets.
    */
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

    /**
    * printCredits()
    * A method prints the credits
    */
    void viewCredits() {
        cout << "This Guessing Game was created by ." << endl;
        cout << "Name : Noureldien Soltan Abdelrahman Ahmed ID : 210209980 Department : SE" << endl;
        cout << "Name : Shiza Khan ID : 200209395 Department : SE" << endl;

    }
};

int main() {
    srand(time(NULL)); // seed for random number generator
//    srand(time(nullptr)); // seed for random number generator 🚀
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Please enter a number between 1 and 5." << endl;
            continue;
        }


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
                cout << "Thank you for playing, we will wait for you again!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    } while (true);
}
