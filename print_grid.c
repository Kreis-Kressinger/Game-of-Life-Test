#include <stdio.h>
#include "print_grid.h"
#include "game.h"

void print_grid(char grid[][GRID_X]){
	for(int i = 0; i < GRID_Y; i++){
		printf("\n");
		for(int j = 0; j < GRID_X; j++){
			if(grid[i][j] == 1){
				printf("#");
			}else{
				printf(".");
			}
		}
	}
}

