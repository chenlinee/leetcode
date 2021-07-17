#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // void solve(char** board, int boardSize, int* boardColSize);
    // [["O","O","O","O","X","X"],['O','O','O','O','O','O'],['O','X','O','X','O','O'],['O','X','O','O','X','O'],['O','X','O','X','O','O'],['O','X','O','O','O','O']]
    char myboard[][6] = {
        {'O','O','O','O','X','X'},
        {'O','O','O','O','O','O'},
        {'O','X','O','X','O','O'},
        {'O','X','O','O','X','O'},
        {'O','X','O','X','O','O'},
        {'O','X','O','O','O','O'}
    };
    int boardSize = sizeof(myboard) / sizeof(myboard[0]);
    char* board[boardSize];
    int boardColSize[boardSize];
    for(int i = 0; i < boardSize; ++i)
    {
        board[i] = myboard[i];
        boardColSize[i] = sizeof(myboard[i]) / sizeof(myboard[i][0]);
    }

    solve(board, boardSize, boardColSize);

    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < boardColSize[i]; ++j)
        {
            printf("%c ", myboard[i][j]);
        }
        printf("\n");
    }

    return 0;
}

