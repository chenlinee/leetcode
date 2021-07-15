#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isValid(char * s){
    if(s == NULL)
    {
        return true;
    }
    int stack_length = 256, stack_add = 256, stack_pointer = 0;
    char* stack = (char*)calloc(stack_length, stack_length * sizeof(char));
    bool ret = true;

    for(int i = 0; s[i] != 0; ++i)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            stack[stack_pointer] = s[i];
            stack_pointer++;
            if(stack_pointer == stack_length)
            {
                stack_length += stack_add;
                stack = (char*)realloc(stack, stack_length * sizeof(char));
            }
        }
        else if(s[i] == '}')
        {
            if(stack_pointer > 0 && stack[stack_pointer - 1] == '{')
            {
                stack_pointer--;
            }
            else
            {
                ret = false;
                break;
            }
        }
        else if(s[i] == ']')
        {
            if(stack_pointer > 0 && stack[stack_pointer - 1] == '[')
            {
                stack_pointer--;
            }
            else
            {
                ret = false;
                break;
            }
        }
        else if(s[i] == ')')
        {
            if(stack_pointer > 0 && stack[stack_pointer - 1] == '(')
            {
                stack_pointer--;
            }
            else
            {
                ret = false;
                break;
            }
        }
    }

    if(stack_pointer != 0)
    {
        ret = false;
    }

    free(stack);
    return ret;
}

