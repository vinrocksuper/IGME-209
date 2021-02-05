#include "hangman.h";
#include <iostream>
using namespace std;
void ShowGallows(int guessLimit) {
	if (guessLimit == 0) {
		cout << "_______" << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
	}
	else if (guessLimit == 1) {
		cout << "_____X_" << endl;
		cout << "|    | " << endl;
		cout << "|    O " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;

	}
	else if (guessLimit == 2) {
		cout << "_____X_" << endl;
		cout << "|    | " << endl;
		cout << "|    O " << endl;
		cout << "|   /| " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;

	}
	else if (guessLimit == 3) {
		cout << "_____X_" << endl;
		cout << "|    | " << endl;
		cout << "|    O " << endl;
		cout << "|   /|\\ " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;

	}
	else if (guessLimit == 4) {
		cout << "_____X_" << endl;
		cout << "|    | " << endl;
		cout << "|    O " << endl;
		cout << "|   /|\\ " << endl;
		cout << "|    | " << endl;
		cout << "|   /  " << endl;
		cout << "|      " << endl;

	}
	else if (guessLimit == 5) {
		cout << "_____X_" << endl;
		cout << "|    | " << endl;
		cout << "|    O " << endl;
		cout << "|   /|\\ " << endl;
		cout << "|    | " << endl;
		cout << "|   / \\ " << endl;
		cout << "|      " << endl;

	}

}


void ShowSolved(char word[], char guesses[]) {
	cout << "Word to solve " << word << endl;
	cout << "Wrong guesses: " << guesses << endl;
}