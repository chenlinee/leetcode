#include <stdio.h>
#include "solution.h"

int main(){
    // [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
    int matrixSize = 5, matrixColSize = 5, target = 0;
    int matrix[5][5] = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int *my_matrix[5];

    for(int i = 0; i < 5; ++i)
    {
        my_matrix[i] = (int *)(matrix + i);
    }

    while(1)
    {
        scanf("%d", &target);
        if(target == -100)
        {
            break;
        }
        if(searchMatrix((int **)my_matrix, matrixSize, &matrixColSize, target))
        {
            printf("found.\n");
        }
        else
        {
            printf("not found.\n");
        }
    }

    return 0;
}

