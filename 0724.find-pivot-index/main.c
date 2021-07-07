#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int pivotIndex(int* nums, int numsSize)
    // nums = [1, 7, 3, 6, 5, 6]
    int nums[] = {1, 7, 3, 6, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int ret = pivotIndex(nums, numsSize);
    printf("ret = %d\n", ret);

    return 0;
}

