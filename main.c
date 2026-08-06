#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "print_grid.h"


#define GRID_X 30
#define GRID_Y 30
#define RULESET {'T','T','C','G','T','T','T','T','T'}

int main(){

	char ruleset[] = RULESET;

	char grid[GRID_Y][GRID_X] = {0};	

	printf("Set up initial generation.");
	
	int creation_mode = 1;
	int y_assign, x_assign;
	while(creation_mode){
		print_grid(GRID_Y, GRID_X, grid);
		printf("\nEnter xy coordinate to toggle a cell. Format: \"Y X\". Enter nonsense to stop. ");
		if(scanf("%d %d", &y_assign, &x_assign) != 2) break;
		if(x_assign <= 0 || y_assign <= 0) continue;
		grid[y_assign-1][x_assign-1] ^= 1;
	}
}
