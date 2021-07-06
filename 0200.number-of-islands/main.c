#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int numIslands(char** grid, int gridSize, int* gridColSize)
    // [['1','1','1','1','0'],['1','1','0','1','0'],['1','1','0','0','0'],['0','0','0','0','0']]
    int gridSize = 4;
    int gridColSize[4];
    char my_grid[4][5] = 
    {
        {'1','1','0','1','0'},
        {'1','1','1','1','0'},
        {'1','0','0','1','0'},
        {'0','0','1','1','0'}
    };
    char* grid[gridSize];
    for(int i = 0; i < gridSize; ++i)
    {
        gridColSize[i] = gridSize;
        grid[i] = my_grid[i];
    }

    int ret = numIslands(grid, gridSize, gridColSize);
    printf("ret = %d\n", ret);

    return 0;
}

