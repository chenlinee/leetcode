#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // bool isValid(char * s)
    char s[] = "{[]}[[";

    printf("ret = %d\n", isValid(s));

    return 0;
}

