#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int longestOnes(int* nums, int numsSize, int k)
    // A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
    int nums[] = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2, numsSize = sizeof(nums) / sizeof(nums[0]);

    int ret = longestOnes(nums, numsSize, k);
    printf("ret = %d\n", ret);

    return 0;
}

