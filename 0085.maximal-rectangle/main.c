#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(void){

    int matrixSize = 4, matrixColSize = 5;
    char* matrix[matrixSize];
    char my_matrix[4][5] = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    for(int i = 0; i < matrixSize; ++i)
    {
        matrix[i] = my_matrix[i];
    }

    int max = maximalRectangle(matrix, matrixSize, &matrixColSize);

    printf("max = %d\n", max);

    return 0;
}

