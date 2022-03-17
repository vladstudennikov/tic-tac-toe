#include <iostream>

using namespace std;

#include "Functions.h"

int main()
{
    char grid[9];
    char grid_copy[9];
    initialize_grid(grid);
    int end = 0;
    do {
        print_grid(grid);
        if (grid_is_full(grid) != 1) {
            player_choose_step(grid);
        }
        if (game_is_over(grid, 'X') == 1) {
            print_grid(grid);
            cout << "\nYou are the winner";
            return 0;
        }

        if (grid_is_full(grid) != 1) {
            computer_choose_step(grid, grid_copy);
        }
        
        if (game_is_over(grid, 'O') == 1) {
            print_grid(grid);
            cout << "\nComputer is a winner";
            return 0;
        }

        if (grid_is_full(grid) == 1) {
            print_grid(grid);
            cout << "\nThe board is full";
            return 0;
        }
    } while (end != 1);
}

