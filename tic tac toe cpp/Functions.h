#include <iostream>

using namespace std;

void initialize_grid(char* array);
int grid_is_full(char* array);
void print_grid(char* array);
void player_choose_step(char* array);
void create_copy_of_grid(char* array, char* array_copy);
int game_is_over(char* array, char a);
void computer_choose_step(char* array, char* array_copy);
