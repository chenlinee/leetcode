#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct array_2d_struct
{
    int row;
    int col;
} array_2d;

/**
 * if a_parent == b_parent, return true;
 * else return false;
 **/
bool find(array_2d** arr, int a_i, int a_j, int b_i, int b_j)
{
    array_2d a_parent = arr[a_i][a_j], b_parent = arr[b_i][b_j], tmp;
    while(a_parent.row != arr[a_parent.row][a_parent.col].row || 
            a_parent.col != arr[a_parent.row][a_parent.col].col)
    {
        a_parent = arr[a_parent.row][a_parent.col];
    }
    for(array_2d m = {a_i, a_j}; m.row != a_parent.row || m.col != a_parent.col;)
    {
        tmp = m;
        m = arr[m.row][m.col];
        arr[tmp.row][tmp.col] = a_parent;
    }
    while(b_parent.row != arr[b_parent.row][b_parent.col].row || 
            b_parent.col != arr[b_parent.row][b_parent.col].col)
    {
        b_parent = arr[b_parent.row][b_parent.col];
    }
    for(array_2d m = {b_i, b_j}; m.row != b_parent.row || m.col != b_parent.col;)
    {
        tmp = m;
        m = arr[tmp.row][tmp.col];
        arr[tmp.row][tmp.col] = b_parent;
    }

    if(a_parent.row == b_parent.row && a_parent.col == b_parent.col)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void merge(array_2d** arr, int a_i, int a_j, int b_i, int b_j)
{
    array_2d a_parent = arr[a_i][a_j], b_parent = arr[b_i][b_j];
    while(a_parent.row != arr[a_parent.row][a_parent.col].row || 
            a_parent.col != arr[a_parent.row][a_parent.col].col)
    {
        a_parent = arr[a_parent.row][a_parent.col];
    }
    while(b_parent.row != arr[b_parent.row][b_parent.col].row || 
            b_parent.col != arr[b_parent.row][b_parent.col].col)
    {
        b_parent = arr[b_parent.row][b_parent.col];
    }

    arr[a_parent.row][a_parent.col] = b_parent;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridSize < 1 || gridColSize == NULL || gridColSize[0] < 1)
    {
        return 0;
    }

    array_2d my_arr[gridSize][gridColSize[0]];
    array_2d* arr[gridSize];
    for(int i = 0; i < gridSize; ++i)
    {
        arr[i] = my_arr[i];
        for(int j = 0; j < gridColSize[0]; ++j)
        {
            my_arr[i][j].row = i;
            my_arr[i][j].col = j;
        }
    }

    int ret = gridSize * gridColSize[0];
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < gridColSize[0]; ++j)
        {
            if(grid[i][j] == '0')
            {
                ret--;
                continue;
            }
            if(i > 0 && grid[i - 1][j] == '1' && !find(arr, i, j, i - 1, j))
            {
                merge(arr, i, j, i - 1, j);
                ret--;
            }
            if(j > 0 && grid[i][j - 1] == '1' && !find(arr, i, j, i, j - 1))
            {
                merge(arr, i, j, i, j - 1);
                ret--;
            }
        }
    }

    return ret;
}
