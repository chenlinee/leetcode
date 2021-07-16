#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int* searchRange(int* nums, int numsSize, int target, int* returnSize)
    int nums[] = {2,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]), returnSize = -1;
    int target = 7;

    int* ret = searchRange(nums, numsSize, target, &returnSize);
    for(int i = 0; i < returnSize; ++i)
    {
        printf("ret[%d] = %d\n", i, ret[i]);
    }

    return 0;
}

