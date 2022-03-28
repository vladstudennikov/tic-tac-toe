#include <iostream>

using namespace std;

class grid {
	char array[9];
	int filled_squares = 0;
public: 
	void initialize_grid();
	int grid_is_full();
	void print_grid();
	void player_choose_step();
	void create_copy_of_grid(char* array_copy);
	int game_is_over(char a);
	int get_filled_squares();
};


