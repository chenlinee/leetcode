#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define UINTBIG_LEN 242
#define FINAL_POS   240

void result_add(char* result, unsigned char* tmp)
{
    unsigned char carry = 0, result_num = 0, tmp_num = 0;
    for(int i = 0; i < FINAL_POS; ++i)
    {
        if(result[i] || tmp[i])
        {
            result_num = result[i] ? result[i] - '0' : 0;
            tmp_num = tmp[i] ? tmp[i] - '0' : 0;
            result[i] = result_num + tmp_num + carry;
            carry = result[i] > 9 ? 1 : 0;
            result[i] = result[i] % 10 + '0';
        }
        else 
        {
            if(carry)
            {
                result[i] = carry + '0';
                carry = 0;
            }
            break;
        }
    }
}

char * multiply(char * num1, char * num2){
    unsigned char a[UINTBIG_LEN];
    unsigned char b[UINTBIG_LEN];
    unsigned char tmp[UINTBIG_LEN];
    char* result = (char*)malloc(UINTBIG_LEN * sizeof(char));
    memset(a, 0, UINTBIG_LEN);
    memset(b, 0, UINTBIG_LEN);
    memset(tmp, 0, UINTBIG_LEN);
    memset(result, 0, UINTBIG_LEN);

    if(num1 == NULL || num2 == NULL)
    {
        return result;
    }

    int a_pos = 0, b_pos = 0;
    for(a_pos = 0; num1[a_pos] != 0; ++a_pos);
    for(int i = 0; i < a_pos; ++i)
    {
        a[i] = num1[a_pos - i - 1] - '0';
    }
    for(b_pos = 0; num2[b_pos] != 0; ++b_pos);
    for(int i = 0; i < b_pos; ++i)
    {
        b[i] = num2[b_pos - i - 1] - '0';
    }

    unsigned char carry = 0, pos = 0;
    for(int i = 0, j = 0; i < a_pos; ++i)
    {
        memset(tmp, 0, UINTBIG_LEN);
        carry = 0;
        for(j = 0; j < b_pos; ++j)
        {
            pos = i + j;
            tmp[pos] = a[i] * b[j] + carry;
            carry = tmp[pos] / 10;
            tmp[pos] = tmp[pos] % 10 + '0';
        }
        if(carry)
        {
            tmp[i + j] = carry + '0';
            carry = 0;
        }
        result_add(result, tmp);
    }

    printf("%s\n", result);
    pos = 0;
    for(pos = 0; result[pos] != 0; ++pos);
    for(int i = 0, j = pos - 1; i < j; ++i, --j)
    {
        char tmp = result[j];
        result[j] = result[i];
        result[i] = tmp;
    }
    if(result[0] == '0')
    {
        result[1] = 0;
    }

    return result;
}

