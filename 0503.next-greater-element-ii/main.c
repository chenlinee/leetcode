#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main()
{
    //int* nextGreaterElements(int* nums, int numsSize, int* returnSize);
    int numsSize = 3, returnSize = -1;
    int nums[3] = {1, 2, 1};

    int* ret = nextGreaterElements(nums, numsSize, &returnSize);

    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", ret[i]);
    }

    printf("\n");

    return 0;
}

