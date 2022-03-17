#include <iostream>

using namespace std;

#include "Functions.h"

void initialize_grid(char* array) {
    for (int i = 0; i < 9; i++) {
        array[i] = ' ';
    }
}

int grid_is_full(char* array) {
    for (int i = 0; i < 9; i++) {
        if (array[i] == ' ') {
            return 0;
        }
    }

    return 1;
}

void print_grid(char* array) {
    cout << array[6] << '|' << array[7] << '|' << array[8] << '\n';
    cout << "-+-+-\n";
    cout << array[3] << '|' << array[4] << '|' << array[5] << '\n';
    cout << "-+-+-\n";
    cout << array[0] << '|' << array[1] << '|' << array[2] << '\n';
}

void player_choose_step(char* array) {
    int step;
    cout << "\nWhat is your next step? (1 - 9)\n";
choose_step: cin >> step;
    if (array[step - 1] == ' ') {
        array[step - 1] = 'X';
    }
    else {
        cout << "\nThis cell is not empty, choose other step (1 - 9)\n";
        goto choose_step;
    }
}

void create_copy_of_grid(char* array, char* array_copy) {
    for (int i = 0; i < 9; i++) {
        array_copy[i] = array[i];
    }
}

int game_is_over(char* array, char a) {
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

void computer_choose_step(char* array, char* array_copy) {
    int step_is_done = 0;
    for (int i = 0; i < 9; i++) {
        create_copy_of_grid(array, array_copy);
        if (array[i] == ' ') {
            array_copy[i] = 'X';
            if (game_is_over(array_copy, 'X') == 1) {
                array[i] = 'O';
                return;
            }
        }
        else {
            continue;
        }
    }

    for (int i = 0; i < 9; i++) {
        create_copy_of_grid(array, array_copy);
        if (array[i] == ' ') {
            array_copy[i] = 'O';
            if (game_is_over(array_copy, 'O') == 1) {
                array[i] = 'O';
                return;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (array[i] == ' ') {
            array[i] = 'O';
            return;
        }
    }
}
