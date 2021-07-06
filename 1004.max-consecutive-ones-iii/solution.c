#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

int longestOnes(int* nums, int numsSize, int k){
    if(nums == NULL || numsSize < 1 || k < 0)
    {
        return 0;
    }

    int left = 0, ret = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == 1)
        {
            ret = MAX(ret, i + 1 - left);
        }
        else
        {
            if(k > 0)
            {
                k--;
                ret = MAX(ret, i + 1 - left);
            }
            else
            {
                while(nums[left] != 0)
                {
                    left++;
                }
                left++;
            }
        }
    }

    return ret;
}

