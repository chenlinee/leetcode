#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char * longestPalindrome(char * s){
    char* ret = (char*)calloc(1, sizeof(char));
    if(s == NULL)
    {
        return ret;
    }
    int len = 0, left = 0;
    for(int i = 0; s[i] != 0; ++i)
    {
        int m = 0;
        if(i - 1 >= 0 && s[i - 1] == s[i])
        {
            m = 1;
            while(i - m - 1 >= 0 && s[i - 1 - m] == s[i + m])
            {
                m++;
            }
            if(len < 2 * m)
            {
                len = 2 * m;
                left = i - m;
            }
        }
        m = 0;
        while(i - m - 1 >= 0 && s[i + m + 1] != 0 && s[i - 1 - m] == s[i + 1 + m])
        {
            m++;
        }
        if(len < 2 * m + 1)
        {
            len = 2 * m + 1;
            left = i - m;
        }
    }
    
    ret = (char*)realloc(ret, len + 1);
    memcpy(ret, s + left, len);
    ret[len] = 0;

    return ret;
}

