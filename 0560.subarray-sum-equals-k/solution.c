#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct sum_struct
{
    int value;
    int index;
} sum_t;

int cmp(const void * a, const void * b)
{
    int a_value = ((sum_t*)a)->value;
    int b_value = ((sum_t*)b)->value;
    
    return a_value - b_value;
}

int find(sum_t* sum, int size, int target)
{
    int i = 0, j = size - 1, mid;
    while(i <= j)
    {
        mid = (i + j) / 2;
        if(sum[mid].value == target)
        {
            return mid;
        }
        if(sum[mid].value > target)
        {
            j = mid - 1;
        }
        if(sum[mid].value < target)
        {
            i = mid + 1;
        }
    }

    return -1;
}

int subarraySum(int* nums, int numsSize, int k){
    if(nums == NULL || numsSize < 1)
    {
        return 0;
    }

    sum_t sort_sum[numsSize];
    int sum[numsSize];
    int total = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        total += nums[i];
        sum[i] = total;
        sort_sum[i].value = total;
        sort_sum[i].index = i;
    }

    qsort((void*)sort_sum, numsSize, sizeof(sort_sum[0]), cmp);

    // for(int i = 0; i < numsSize; ++i)
    // {
    //     printf("sort_sum[%d].value = %d\n", sort_sum[i].index, sort_sum[i].value);
    // }

    int big, big_index, ret = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        big = sum[i] + k - nums[i];
        big_index = find(sort_sum, numsSize, big);
        // printf("big_index = %d\n", big_index);
        if(big_index != -1)
        {
            int tmp = big_index;
            while(tmp < numsSize && sort_sum[tmp].value == big)
            {
                if(sort_sum[tmp].index >= i)
                {
                    ret++;
                }
                tmp++;
            }
            tmp = big_index - 1;
            while(tmp >=0 && sort_sum[tmp].value == big)
            {
                if(sort_sum[tmp].index >= i)
                {
                    ret++;
                }
                tmp--;
            }
        }
    }

    return ret;
}

