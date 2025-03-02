#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateRandomNumber();
int getPlayerGuess();
void printAnswer(int guess, int secretNumber);
void playGuessIt();
bool askToPlayAgain();

int main(){
    do{
        playGuessIt();
    }while(askToPlayAgain());
    cout << "Thanks for playing the game" << endl;
    return 0;
}

int generateRandomNumber(){
    srand(time(0));
    return rand() % 100 + 1;
}
int getPlayerGuess(){
    int guess;
    cout << endl << "Enter your guess (1...100): ";
    cin >> guess;
    return guess;
}
void printAnswer(int guess, int secretNumber){
    if(guess > secretNumber){
        cout << "Your number is too big." << endl;
    }else if(guess < secretNumber){
        cout << "Your number is too small." << endl;
    }else{
        cout << "Congratulation! You win." << endl;
    }
}
void playGuessIt(){
    int secretNumber = generateRandomNumber();
    int guess;
    int time = 0;
    int score = 100;
    do{
        guess = getPlayerGuess();
        printAnswer(guess, secretNumber);
        time++;
        if(time > 1){
            score-=1;
        }
        cout << "Number of guesses: " << time << endl;
        cout << "Score: " << score << endl;
    }while (guess != secretNumber);
}
bool askToPlayAgain(){
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return(choice == 'y' || choice == 'Y');
}
