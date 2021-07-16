#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int search(int* nums, int numsSize, int target){
    if(nums == NULL || numsSize < 1)
    {
        return -1;
    }
    int left = 0, right = numsSize - 1, mid;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] > target)
        {
            if(nums[mid] < nums[left])
            {
                left++;
                right = mid - 1;
                mid = (left + right) / 2;
            }
            else
            {
                if(target == nums[left])
                {
                    return left;
                }
                else if(target > nums[left])
                {
                    left++;
                    right = mid - 1;
                    mid = (left + right) / 2;
                }
                else
                {
                    left = mid + 1;
                    mid = (left + right) / 2;
                }
            }
        }
        else
        {
            if(nums[mid] > nums[right])
            {
                left = mid + 1;
                right--;
                mid = (left + right) / 2;
            }
            else
            {
                if(target == nums[right])
                {
                    return right;
                }
                else if(target < nums[right])
                {
                    left = mid + 1;
                    right--;
                    mid = (left + right) / 2;
                }
                else
                {
                    right = mid - 1;
                    mid = (left + right) / 2;
                }
            }
        }
    }

    return -1;
}

