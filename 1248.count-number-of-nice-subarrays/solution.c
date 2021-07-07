#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int numberOfSubarrays(int* nums, int numsSize, int k){
    if(nums == NULL || numsSize < 1 || k < 1)
    {
        return 0;
    }

    int ret = 0, left = -1, last_left = -1;

    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] % 2 == 0)
        {
            // 计算子数组数量
            if(k == 0)
            {
                ret += left - last_left;
            }
        }
        else
        {
            // 子数组内奇数个数小于 k
            if(k > 0)
            {
                k--;
            }
            // 子数组内奇数个数等于 k
            if(k == 0)
            {
                // 保留上一个奇数的位置，移动 left 到符合条件的最左边奇数位置
                last_left = left;
                left++;
                while(left < numsSize && nums[left] % 2 == 0)
                {
                    left++;
                }
                ret += left - last_left;
            }
        }
    }

    return ret;
}
