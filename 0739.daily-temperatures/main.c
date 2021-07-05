#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main()
{
    //int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize);
    int temperaturesSize = 8, returnSize = -1;
    int temperatures[8] = {73,74,75,71,69,72,76,73};

    int* ret = dailyTemperatures(temperatures, temperaturesSize, &returnSize);

    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", ret[i]);
    }

    printf("\n");
    free(ret);
    return 0;
}

