#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    if(temperatures == NULL || temperaturesSize < 1 || returnSize == NULL)
    {
        return NULL;
    }
    int stack[temperaturesSize];
    int count = 0;
    int* ret = (int*)calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;

    for(int i = temperaturesSize - 1; i >= 0; --i)
    {
        while(count > 0 && temperatures[i] >= temperatures[stack[count - 1]])
        {
            count--;
        }
        if(count == 0)
        {
            ret[i] = 0;
        }
        else
        {
            ret[i] = stack[count - 1] - i;
        }
        stack[count] = i;
        count++;
    }

    return ret;
}
