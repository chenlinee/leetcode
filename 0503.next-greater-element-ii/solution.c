#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    while(nums == NULL || returnSize == NULL || numsSize < 1)
    {
        return NULL;
    }

    *returnSize = numsSize;
    int stack[numsSize];
    memset(stack, 0, numsSize * sizeof(int));
    int count = 0;
    int* ret = (int*)calloc(numsSize, sizeof(int));
    memset(ret, 0, numsSize * sizeof(int));

    for(int i = 0; i < numsSize; ++i)
    {
        while(count > 0 && nums[i] > nums[stack[count - 1]])
        {
            ret[stack[count - 1]] = nums[i];
            count--;
        }
        stack[count] = i;
        ++count;
    }

    if(count > 0)
    {
        for(int i = 0; i < numsSize && count > 0; ++i)
        {
            if(i == stack[count - 1])
            {
                break;
            }
            while(count > 0 && nums[i] > nums[stack[count - 1]])
            {
                ret[stack[count - 1]] = nums[i];
                count--;
            }
        }
    }

    while(count > 0)
    {
        ret[stack[count - 1]] = -1;
        --count;
    }

    return ret;
}

