#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int pivotIndex(int* nums, int numsSize)
{
    if(nums == NULL || numsSize < 1)
    {
        return - 1;
    }
    if(numsSize == 1)
    {
        return 0;
    }

    int sum[numsSize], ret = -1;
    memset(sum, 0, numsSize * sizeof(sum[0]));

    sum[0] = nums[0];
    for(int i = 1; i < numsSize; ++i)
    {
        sum[i] = sum[i - 1] + nums[i];
    }

    for(int i = 0; i < numsSize; ++i)
    {
        if(i == 0 && sum[numsSize - 1] - sum[0] == 0)
        {
            ret = 0;
            break;
        }
        if(i == numsSize - 1 && sum[numsSize - 2] == 0)
        {
            ret = numsSize - 1;
            break;
        }
        if(i != 0 && i != numsSize && sum[i - 1] == sum[numsSize - 1] - sum[i])
        {
            ret = i;
            break;
        }
    }

    return ret;
}

