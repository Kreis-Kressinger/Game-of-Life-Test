#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "game.h"
#include "print_grid.h"

static int toggle_pixel(int y_assign, int x_assign, char grid[GRID_Y][GRID_X] ){
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
	char grid[GRID_Y][GRID_X] = {0};

	printf("Set up initial generation.");

	int creation_mode = 1;
	int y_assign, x_assign;
	char template[10];
	while (creation_mode) {
		print_grid(grid);

		printf("\nEnter xy coordinate to toggle a cell. "
				"Format: \"Y X\" or \"Y X TEMPLATE\". "
				"Enter nonsense to stop. ");

		// Read one complete line from stdin.
		// This avoids scanf() waiting for a possible third argument
		// on the next input line.
		char line[100];

		if (fgets(line, sizeof line, stdin) == NULL) {
			break;  // EOF or input error
		}

		// Parse the line:
		//   "Y X"          -> gelesene_werte == 2
		//   "Y X TEMPLATE" -> gelesene_werte == 3
		//
		// %9s limits the template string to 9 characters
		// and prevents writing beyond the template buffer.
		int gelesene_werte =
			sscanf(line, "%d %d %9s",
					&y_assign, &x_assign, template);

		// Fewer than two successfully read values means that
		// no valid coordinate pair was entered.
		if (gelesene_werte < 2) {
			break;
		}

		// A third argument was entered, so interpret it
		// as the name of a predefined template.
		if (gelesene_werte == 3) {
			printf("Template erkannt: %s\n", template);

			// Create a 2 x 2 still-life block.
			if (strcmp(template, "block") == 0) {

				// Iterate over the two rows of the block.
				for (int y_index = y_assign;
						y_index < y_assign + 2;
						y_index++) {

					// Iterate over the two columns of the block.
					for (int x_index = x_assign;
							x_index < x_assign + 2;
							x_index++) {

						// Toggle each of the four cells.
						toggle_pixel(y_index, x_index, grid);
					}
				}

				printf("Block created!\n");
			}
		}
		else {
			// No template was given:
			// toggle only the single cell at (y_assign, x_assign).
			if (toggle_pixel(y_assign, x_assign, grid)) {
				continue;
			}
		}
	}
	printf("starting game...");
	//game(GRID_Y,GRID_X,grid);
	game(grid); // grid hat keine dynamische Größe (Größe ist über Makros definiert und steht schon zur
		    // Compilezeit fest -> GRID_Y,GRID_X brauchen nicht übergeben zu werden.
}
