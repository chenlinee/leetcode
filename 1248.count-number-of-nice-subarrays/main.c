#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int numberOfSubarrays(int* nums, int numsSize, int k)
    // nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    int nums[] = {2,2,2,1,2,2,1,2,2,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]), k = 2;

    int ret = numberOfSubarrays(nums, numsSize, k);
    printf("ret = %d\n", ret);

    return 0;
}

