#include <iostream>

using namespace std;

#include "Functions.h"

int main()
{
    grid a;
    grid grid_copy;
    a.initialize_grid();
    do {
        a.print_grid();
        if (a.get_filled_squares() != 9) {
            a.player_choose_step();
        }
        if (a.game_is_over('X') == 1) {
            a.print_grid();
            cout << "\nYou are the winner";
            return 0;
        }

        if (a.get_filled_squares() != 9) {
            a.computer_choose_step(grid_copy);
        }

        if (a.game_is_over('O') == 1) {
            a.print_grid();
            cout << "\nComputer is a winner";
            return 0;
        }

        if (a.get_filled_squares() == 9) {
            a.print_grid();
            cout << "\nThe board is full";
            return 0;
        }
    } while (true);
}

