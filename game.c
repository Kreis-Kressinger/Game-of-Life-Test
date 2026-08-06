#include "game.h"
#include "print_grid.h"
#include "sleep_ms.h"

int number_of_neighbors(int y, int x, grid[GRID_Y][GRID_X]){
	int non; // number of neighbors
	/*
	 * We have to cover three different cases: a cell can either have
	 * three neighbors (a), five neighbors (b), or eight neigbors (c), depending on the
	 * position wrt. (with respect to) the boundaries
	 *
	 * cosidered cell = x, neighbors = 1 
	 *
	 * (a) x 1 0 . 0 < line with index y = 0
	 *     1 1 0 . 0
	 *     . . . . 0
	 *     0 0 0 . 0 < line with index y = GRID_Y -1
	 *     ^       ^ col with index x = GRID_X - 1
	 *     |
	 *     col with index x = 0
	 *
	 * (c) 1 1 1 . 0 < line with index y = 0
	 *     1 x 1 . 0
	 *     1 1 1 . 0 
	 *     . . . . 0
	 *     0 0 0 . 0 < line with index y = GRID_Y -1
	 *     ^       ^ col with index x = GRID_X - 1
	 *     |
	 *     col with index x = 0
	 *
	 * (b) 1 1 0 . 0 < line with index y = 0
	 *     x 1 0 . 0
	 *     1 1 0 . 0
	 *     . . . . 0
	 *     0 0 0 . 0 < line with index y = GRID_Y -1
	 *     ^       ^ col with index x = GRID_X - 1
	 *     |
	 *     col with index x = 0
	 *
	 * SOLUTION STRATEGY:
	 * FIRST ADD UP ADJACENT CELLS, INCREMENT non IF THEY ARE LIVING
	 *
	 * ANOTHER SOLUTION WOULD BE TO USE CYCLIC BOUNDARIES i.e. if you leave
	 * the arry on top, you enter on the bottom (resp. leave left, you enter on the right like Bernd
	 * das Brot). In this case, any cell has always 8 neighbors that have to be checked...
	 * Behavior could be switched by a macro variable
	 * CYCLIC_BC = 1
	 *
	 * up to you...
	 * /
	
	if ( )  // CASE (a)
			
	// CASE (b)
	
	// CASE (c)
	... TO BE CONTINUED...
	... TODO ...

	return non; // like a frenchman
}

void game(int y, int x, char grid[y][x])
{
	printf("game started...");
	while (1) {
		print_grid(y, x, grid);
		sleep_ms(1000);
		char ingrid[GRID_Y][GRID_X]={0}; // iteration grid :)
		for (int j = 0; j < GRID_Y; j++){
			for (int i = 0; i < GRID_X, i++){
				int non = number_of_neighbors(j,i,grid)
				int setval = 0;
				if (RULESET[non]=='0'){
					// do not do anything
				}
				else{if(RULESET[non]=='C')
					setval = grid[j][i];
				}
				else{if(RULESET[non]=='1')
					setval = 1;
				}
				ingrid[j][i] = setval;
			}
		}
		grid = ingrid; // geht das so?!
	}
}
