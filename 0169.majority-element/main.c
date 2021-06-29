#include <stdio.h>
#include "solution.h"

int main(){
    int nums[10] = {1, 3, 1, 3, 1, 1, 6, 1, 0, 1};
    int numsSize = 10;
    
    int ret = majorityElement(nums, numsSize);

    printf("ret = %d\n", ret);

    return 0;
}

