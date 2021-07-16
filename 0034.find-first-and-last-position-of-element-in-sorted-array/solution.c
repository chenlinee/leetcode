#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* ret = (int*)malloc((*returnSize) * sizeof(int));
    ret[0] = -1;
    ret[1] = -1;
    if(nums == NULL || numsSize < 1)
    {
        return ret;
    }

    int left = 0, right = numsSize - 1, mid;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] >= target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(nums[right + 1] == target)
    {
        ret[0] = right + 1;
    }
    else
    {
        return ret;
    }

    left = 0, right = numsSize - 1;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    ret[1] = left - 1;

    return ret;
}

