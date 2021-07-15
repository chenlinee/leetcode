#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int my_log10(int value)
{
    if(value == 0)
    {
        return 1;
    }
    int ret = 0;
    while(value > 0)
    {
        ret++;
        value = value / 10;
    }

    return ret;
}

void fillString(char* str, int* count, int value)
{
    if(value < 0 || value > 255)
    {
        printf("error.\n");
        return;
    }
    if(value == 0)
    {
        str[(*count)--] = '0';
    }
    else
    {
        while(value > 0)
        {
            str[(*count)--] = value % 10 + '0';
            value = value / 10;
        }
    }
}

char* genIpString(int a, int b, int c, int d)
{
    if(a < 0 || b < 0 || c < 0 || d < 0 || a > 255 || b > 255 || c > 255 || d > 255)
    {
        printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
        return NULL;
    }
    int length = my_log10(a) + my_log10(b) + my_log10(c) + my_log10(d);
    char* ret = (char*)malloc((length + 4) * sizeof(char));
    memset(ret, 0, sizeof(length + 4) * sizeof(char));
    int count = length + 2;
    fillString(ret, &count, d);
    ret[count--] = '.';
    fillString(ret, &count, c);
    ret[count--] = '.';
    fillString(ret, &count, b);
    ret[count--] = '.';
    fillString(ret, &count, a);

    return ret;
}

char ** restoreIpAddresses(char * s, int* returnSize){
    if(s == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int length = 0;
    *returnSize = 0;
    for(;s[length] != 0; ++length);
    if(length < 4 || length > 12)
    {
        return NULL;
    }

    char** ret = (char**)malloc((*returnSize) * sizeof(char*));

    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 1; i <= length - 3; ++i)
    {
        a = a * 10 + s[i - 1] - '0';
        if(a > 255 || i > 3 || (s[0] == '0' && i > 1))
        {
            break;
        }
        b = 0;
        for(int j = i + 1; j <= length - 2; ++j)
        {
            b = b * 10 + s[j - 1] - '0';
            if(b > 255 || j - i > 3 || (s[i] == '0' && j - i > 1))
            {
                break;
            }
            c = 0;
            for(int m = j + 1; m <= length - 1; ++m)
            {
                c = c * 10 + s[m - 1] - '0';
                if(c > 255 || m - j > 3 || (s[j] == '0' && m - j > 1))
                {
                    break;
                }
                if(length - m > 3 || (s[m] == '0' && length - m > 1))
                {
                    continue;
                }
                d = 0;
                for(int n = m; n < length; ++n)
                {
                    d = d * 10 + s[n] - '0';
                }
                if(d <= 255)
                {
                    (*returnSize)++;
                    ret = (char**)realloc(ret, (*returnSize) * sizeof(char*));
                    ret[*returnSize - 1] = genIpString(a, b, c, d);
                }
            }
        }
    }

    return ret;
}

