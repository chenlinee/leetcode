#include <iostream>
#include "solution.h"
#include <unordered_map>

using namespace std;

int subarraySum(int* nums, int numsSize, int k){
    unordered_map<int, int> mp;
    mp[0] = 1;

    int sum = 0, ret = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
        if(mp.find(sum - k) != mp.end())
        {
            ret += mp[sum - k];
        }
        if(mp.find(sum) != mp.end())
        {
            mp[sum]++;
        }
        else
        {
            mp[sum] = 1;
        }
    }
    return ret;
}
