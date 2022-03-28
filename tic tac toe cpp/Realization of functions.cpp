#include <iostream>

using namespace std;

#include "Functions.h"

void grid::create_copy_of_grid(char* array_copy) {
    for (int i = 0; i < 9; i++) {
        array_copy[i] = array[i];
    }
}

int grid::game_is_over(char a) {
    for (int i = 0; i < 7; i += 3) {
        if (array[i] == a && array[i + 1] == a && array[i + 2] == a) {
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (array[i] == a && array[i + 3] == a && array[i + 6] == a) {
            return 1;
        }
    }

    if (array[0] == a && array[4] == a && array[8] == a)  return 1;
    if (array[2] == a && array[4] == a && array[6] == a)  return 1;

    return 0;
}

void grid::initialize_grid() {
    for (int i = 0; i < 9; i++) {
        array[i] = ' ';
    }
}

int grid::grid_is_full() {
    for (int i = 0; i < 9; i++) {
        if (array[i] == ' ') {
            return 0;
        }
    }

    return 1;
}


void grid::print_grid() {
    cout << array[6] << '|' << array[7] << '|' << array[8] << '\n';
    cout << "-+-+-\n";
    cout << array[3] << '|' << array[4] << '|' << array[5] << '\n';
    cout << "-+-+-\n";
    cout << array[0] << '|' << array[1] << '|' << array[2] << '\n';
}

void grid::player_choose_step() {
    int step;
    cout << "\nWhat is your next step? (1 - 9)\n";
choose_step: cin >> step;
    if (array[step - 1] == ' ') {
        array[step - 1] = 'X';
        ++filled_squares;
    }
    else {
        cout << "\nThis cell is not empty, choose other step (1 - 9)\n";
        goto choose_step;
    }
}

int grid::get_filled_squares() {
    return filled_squares;
}