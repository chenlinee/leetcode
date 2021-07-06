#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int minSubArrayLen(int target, int* nums, int numsSize)
    // [2,3,1,2,4,3], 7
    int target = 7, numsSize = 6;
    int nums[6] = {2,3,1,2,4,3};

    int ret = minSubArrayLen(target, nums, numsSize);
    printf("ret = %d\n", ret);

    return 0;
}

