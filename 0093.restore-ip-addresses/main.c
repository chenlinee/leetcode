#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // char ** restoreIpAddresses(char * s, int* returnSize)
    char s[] = "255255255255";
    int returnSize = -1;
    char** ret = restoreIpAddresses(s, &returnSize);
    for(int i = 0; i < returnSize; ++i)
    {
        printf("ret[%d] = %s\n", i, ret[i]);
    }

    return 0;
}

