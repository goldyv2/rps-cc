/// Some crap C++ code.

#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <unistd.h>

using namespace std;

enum RPSChoice {
    NONE = -1,

    ROCK,
    PAPER,
    SCISSORS,
};

int parse_string_choice(const string string_choice, RPSChoice& choice) {
    if (string_choice == "ROCK") choice = RPSChoice::ROCK;
    if (string_choice == "PAPER") choice = RPSChoice::PAPER;
    if (string_choice == "SCISSORS") choice = RPSChoice::SCISSORS;

    if (choice != -1) {
        return 0;
    }

    return 1;
}

void display_countdown() {
    double seconds = 0.5;
    int microseconds = (seconds * 1000) * 1000;

    cout << "Rock! " << flush;
    usleep(microseconds);

    cout << "Paper! " << flush;
    usleep(microseconds);

    cout << "Scissors! " << flush;
    usleep(microseconds);

    cout << "SHOOT! " << flush;
    usleep(microseconds);
}

int main() {
    srand(time(0));

    display_countdown();

    string user_string_choice;

    cout << "\n\nPick your choice ( rock | paper | scissors ): ";
    cin >> user_string_choice;

    transform(user_string_choice.begin(), user_string_choice.end(), user_string_choice.begin(), ::toupper);

    RPSChoice user_choice = RPSChoice::NONE;

    if (parse_string_choice(user_string_choice, user_choice) == 1) {
        cout << "Failed to parse user choice! Are you sure you didn't mistype?" << endl;
        return 1;
    }

    int random_number = rand() % 3;
    RPSChoice computer_choice = static_cast<RPSChoice>(random_number);

    if (user_choice == computer_choice) {
        cout << endl << "You both picked " << user_string_choice << "!" << endl;
        return 0;
    }

    if (user_choice + 1 == computer_choice || computer_choice + 2 == user_choice) {
        cout << endl << "YOU LOST!" << endl;
        return 0;
    }

    cout << endl << "YOU WON!" << endl;
}