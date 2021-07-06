#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN(a, b) (a) < (b) ? (a) : (b)

int minSubArrayLen(int target, int* nums, int numsSize){
    if(nums == NULL || numsSize < 1)
    {
        return 0;
    }

    int tail = 0;
    int min = 0x7fffffff, sum = 0;

    for(int i = 0; i < numsSize; ++i)
    {
        // [2,3,1,2,4,3], 7
        sum += nums[i];
        while(sum - nums[tail] >= target)
        {
            sum -= nums[tail];
            tail++;
        }
        if(sum >= target)
        {
            min = MIN(min, i + 1 - tail);
        }
    }

    return sum >= target ? min : 0;
}

/*
    int head = 0, tail = 0, sum = 0, min = -1;

    for(int i = 0; i < numsSize; ++i)
    {
        if(sum < target)
        {
            sum += nums[i];
            head++;
            if(sum >= target)
            {
                sum = sum - nums[tail];
                while(sum >= target)
                {
                    tail++;
                    sum = sum - nums[tail];
                }
                sum = sum + nums[tail];
                min = head - tail;
            }
        }
        else
        {
            head++;
            sum = sum + nums[head - 1] - nums[tail];
            while(sum >= target)
            {
                tail++;
                sum = sum - nums[tail];
            }
            sum = sum + nums[tail];
            if(sum >= target && head - tail <= min)
            {
                min = head - tail;
            }
        }
    }

    if(min != -1)
    {
        return min;
    }
    else
    {
        return 0;
    }
}
*/
