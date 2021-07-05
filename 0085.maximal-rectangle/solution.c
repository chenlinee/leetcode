#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max(a, b) (a) > (b) ? (a) : b

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if(matrix == NULL || matrixSize < 1 || matrixColSize == NULL || *matrixColSize < 1)
    {
        return 0;
    }

    int width[matrixSize][matrixColSize[0]];
    memset(width, 0, sizeof(int) * matrixSize * matrixColSize[0]);
    for(int i = 0; i < matrixSize; ++i)
    {
        width[i][0] = matrix[i][0] == '1' ? 1 : 0;
        for(int j = 1; j < matrixColSize[0]; ++j)
        {
            width[i][j] = matrix[i][j] == '1' ? width[i][j - 1] + 1 : 0;
        }
    }

    int stack[matrixSize];
    int left[matrixSize];
    memset(stack, 0, sizeof(int) * matrixSize);
    memset(left, 0, sizeof(int) * matrixSize);
    int ret = 0, current = 0, count = 0;
    for(int j = 0; j < matrixColSize[0]; ++j)
    {
        count = 0;
        for(int i = 0; i < matrixSize; ++i)
        {
            while(count > 0 && width[stack[count - 1]][j] >= width[i][j])
            {
                count--;
            }
            if(count == 0)
            {
                left[i] = -1;
            }
            else
            {
                left[i] = stack[count - 1];
            }
            stack[count] = i;
            count++;
        }

        count = 0;

        for(int i = matrixSize - 1; i >= 0; --i)
        {
            while(count > 0 && width[stack[count - 1]][j] >= width[i][j])
            {
                count--;
            }
            if(count == 0)
            {
                //left[i] = -1;
                current = (matrixSize - left[i] - 1) * width[i][j];
                ret = max(current, ret);
            }
            else
            {
                //left[i] = stack[count - 1];
                current = (stack[count - 1] - left[i] - 1) * width[i][j];
                ret = max(current, ret);
            }
            stack[count] = i;
            count++;
        }
    }

    return ret;
}
