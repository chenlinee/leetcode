#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int subarraySum(int* nums, int numsSize, int k)
    // nums = [1,1,1], k = 2
    int nums[] = {1,2,3,-3,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]), k = 3;

    int ret = subarraySum(nums, numsSize, k);
    printf("ret = %d\n", ret);

    return 0;
}
