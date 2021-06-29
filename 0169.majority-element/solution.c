#include "solution.h"

/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */

// @lc code=start

// 采用抵消的方法；
int majorityElement(int* nums, int numsSize){
    if(numsSize <= 0)
    {
        return 0;
    }
    int count = 1, current_num = nums[0];
    
    for(int i = 1; i < numsSize; ++i)
    {
        if(count == 0)
        {
            count = 1;
            current_num = nums[i];
            continue;
        }
        if(nums[i] == current_num)
        {
            ++count;
        }
        else
        {
            --count;
        }
    }

    return current_num;
}
