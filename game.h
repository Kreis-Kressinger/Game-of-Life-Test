#pragma once

#define GRID_Y 20
#define GRID_X 60
#define CYCLIC_BC 1

#define RULESET "00C100000"
// 0 = dead, 1 = alive, C = copy state from prev. generation

void game(char grid[][GRID_X]);
