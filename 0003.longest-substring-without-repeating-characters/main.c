#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int lengthOfLongestSubstring(char * s)
    char s[] = "bbbbbbb";

    int ret = lengthOfLongestSubstring(s);
    printf("ret = %d\n", ret);

    return 0;
}

