#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

int lengthOfLongestSubstring(char * s){
    if(s == NULL)
    {
        return 0;
    }

    int left = 0;
    int all_char[255];
    int ret = 0;
    memset(all_char, 0, 255 * sizeof(int));
    for(int i = 0; s[i] != 0; ++i)
    {
        if(all_char[(int)s[i]] == 0)
        {
            all_char[(int)s[i]] = 1;
            ret = MAX(ret, i + 1 - left);
        }
        else
        {
            while(s[left] != s[i] && left < i)
            {
                all_char[(int)s[left]] = 0;
                left++;
            }
            left++;
        }
    }
    return ret;
}

