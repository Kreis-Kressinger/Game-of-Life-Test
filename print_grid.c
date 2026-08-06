#include <stdio.h>

void print_grid(int y, int x, char grid[y][x]){
	for(int i = 0; i < y; i++){
		printf("\n");
		for(int j = 0; j < x; j++){
			if(grid[i][j] == 1){
				printf("#");
			}else{
				printf(".");
			}
		}
	}
}

