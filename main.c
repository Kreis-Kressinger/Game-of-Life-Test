#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "print_grid.h"


#define GRID_X 30
#define GRID_Y 30
//#define RULESET {'T','T','C','G','T','T','T','T','T'}
//no. of living neigbors
//                0   1   2   3   4   5   6   7   8
#define RULESET {'0','0','C','1','0','0','0','0','0'}
// 0 = dead, 1 = alive, C = copy state from prev. generation

int toggle_pixel(int y_assign, int x_assign, char grid[GRID_Y][GRID_X] ){
	// Validierung der Koordinaten
	if (x_assign < 1 || x_assign > GRID_X ||
			y_assign < 1 || y_assign > GRID_Y) {
		puts("Coordinate outside the grid.");
		// Wichtig: Bei falscher Eingabe den Puffer leeren, um Endlosschleifen zu vermeiden
		while(getchar() != '\n'); 
		return 1;
	}	

	grid[y_assign-1][x_assign-1] ^= 1; // Prakti toggelt... :) nice
	return 0; // Erfolg! :)
}

int main(void){

	char ruleset[] = RULESET;

	char grid[GRID_Y][GRID_X] = {0};	

	printf("Set up initial generation.");

	int creation_mode = 1;
	int y_assign, x_assign;
	char template[10];
	while(creation_mode){
		print_grid(GRID_Y, GRID_X, grid);
		printf("\nEnter xy coordinate to toggle a cell. Format: \"Y X\" oder \"Y X TEMPLATE\". Enter nonsense to stop. ");

		int gelesene_werte = scanf("%d %d %9s", &y_assign, &x_assign, template);

		// Wenn nicht einmal 2 Zahlen eingegeben wurden (z.B. Buchstabe oder "nonsense")
		if (gelesene_werte < 2) {
			break;
		}

		// Wenn 3 Werte eingegeben wurden, wurde ein Template mitgegeben
		if (gelesene_werte == 3) {
			printf("Template erkannt: %s\n", template);
			if (strcmp(template,"block") == 0){ // <-- WTF ist das für eine unintuitive K*acke
			        for (int y_index = y_assign; y_index < y_assign+2; y_index++)
				{
					for (int x_index = x_assign; x_index < x_assign+2; x_index++)
					{
						toggle_pixel(y_index,x_index,grid);
					}
				}
				printf("Block created!");
			}
		}
		else{
			if (toggle_pixel(y_assign,x_assign,grid))
			{
				continue; // Fehler
			}
		}
	}
//	Please look at game.c, started implementation...
/*	
	printf("starting game...");
	game(GRID_Y,GRID_X,grid);
*/
}
