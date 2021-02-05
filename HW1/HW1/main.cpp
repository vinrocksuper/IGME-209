#include <iostream>
using namespace std;
#include "hangman.h";
int main()
{
    // Sets up word to be guessed and stuff
    char toBeGuessed[100] = "dialect";
    char correctLetters[100] = "_______";
    char incorrectLetters[100] = "";
    bool gameClear = false;
    int livesLost = 0;
    cout << "Welcome to hangman! Try to guess the word, one letter at a time before the stickman is hanged!" << endl;

    char guess[100]="";

    while (livesLost < 5 &&  !gameClear) {
        cout << "Type a letter and hit enter: ";
        cin >> guess;
        
        if (strstr(toBeGuessed,guess)) {
            cout << "Correct! Your character lives for another letter!" << endl;
            
            if (guess[0] == 'd') {
                correctLetters[0] = 'd';
            }
            else if (guess[0] == 'i') {
                correctLetters[1] = 'i';
            }
            else if (guess[0] == 'a') {
                correctLetters[2] = 'a';
            }
            else if (guess[0] == 'l') {
                correctLetters[3] = 'l';
            }
            else if (guess[0] == 'e') {
                correctLetters[4] = 'e';
            }
            else if (guess[0] == 'c') {
                correctLetters[5] = 'c';
            }
            else if (guess[0] == 't') {
                correctLetters[6] = 't';
            }
            ShowSolved(correctLetters, incorrectLetters);
        }
        else {
            if (strstr(incorrectLetters, guess)) {
                cout << "You have already tried this letter. Please type another." << endl;
            }
            else {
                livesLost++;
                strcat_s(incorrectLetters, guess);
                ShowGallows(livesLost);
                ShowSolved(correctLetters,incorrectLetters);
            }
            
        }
        if (strcmp(correctLetters, toBeGuessed) == 0) {
            gameClear = true;
        }
    }
    if (gameClear) {
        cout << "Congrats on winning!" << endl;
    }
    else {
        cout << "You didn't win, but feel free to try again!";
    }
    

}


