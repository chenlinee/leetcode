#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int row = 0, col = 0;
bool** visited;

bool search(int i, int j, char** board)
{
    if(i < 0 || i >= row || j < 0 || j >= col)
    {
        printf("search error, i = %d, j = %d\n", i, j);
        return false;
    }
    if(board[i][j] == 'X' || visited[i][j])
    {
        return true;
    }
    if((i == 0 || i == row - 1 || j == 0 || j == col - 1) && board[i][j] == 'O')
    {
        return false;
    }
    visited[i][j] = true;

    bool ret = true;
    if(i > 0)       {ret = search(i - 1, j, board) && ret;}
    if(i < row - 1) {ret = search(i + 1, j, board) && ret;}
    if(j > 0)       {ret = search(i, j - 1, board) && ret;}
    if(j < col - 1) {ret = search(i, j + 1, board) && ret;}

    return ret;
}

void fill(int i, int j, char** board)
{
    if(i < 0 || i >= row || j < 0 || j >= col)
    {
        return;
    }
    if(board[i][j] == 'X')
    {
        return;
    }
    board[i][j] = 'X';
    if(i > 0)   {fill(i - 1, j, board);}
    if(i < row) {fill(i + 1, j, board);}
    if(j > 0)   {fill(i, j - 1, board);}
    if(j < col) {fill(i, j + 1, board);}
}

void solve(char** board, int boardSize, int* boardColSize){
    if(board == NULL || boardSize < 3 || boardColSize[0] < 3)
    {
        return;
    }

    row = boardSize;
    col = boardColSize[0];

    visited = (bool**)calloc(row, sizeof(bool*));
    for(int i = 0; i < row; ++i)
    {
        visited[i] = (bool*)calloc(col, sizeof(bool));
    }

    for(int i = 1; i < row - 1; ++i)
    {
        for(int j = 1; j < col - 1; ++j)
        {
            if(!visited[i][j] && board[i][j] == 'O' && search(i, j, board))
            {
                fill(i, j, board);
            }
        }
    }

    for(int i = 0; i < row; ++i)
    {
        free(visited[i]);
    }
    free(visited);
}

