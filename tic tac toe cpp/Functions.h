#include <iostream>

using namespace std;

class grid {
	int filled_squares = 0;
public: 
	char array[9];
	void initialize_grid();
	int grid_is_full();
	void print_grid();
	void player_choose_step();
	void computer_choose_step(grid grid_copy);
	void create_copy_of_grid(grid array_copy);
	int game_is_over(char a);
	int get_filled_squares();
};


