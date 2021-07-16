#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int search(int* nums, int numsSize, int target)
    int nums[] = {4,5,6,7,0,1,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    printf("ret = %d\n", search(nums, numsSize, target));

    return 0;
}

