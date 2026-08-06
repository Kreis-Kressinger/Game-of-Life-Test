#include <time.h>
#include "print_grid.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#endif
#ifdef __unix__
#include <unistd.h>
#define SLEEP(ms) sleep(ms / 100)
#endif

void game(int x, int y, char grid[y][x]){
	while(1){
		print_grid(x, y, grid);
		SLEEP(100);
	}
}
