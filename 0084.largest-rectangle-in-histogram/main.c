#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){
    /*
    int heightsSize = 100000;
    int* heights = (int*)malloc(heightsSize * sizeof(int));

    for(int i = 0; i < heightsSize; ++i)
    {
        heights[i] = 7303;
    }
    */
    //int heights[20] = {3,5,5,2,5,5,6,6,4,4,1,1,2,5,5,6,6,4,1,3};
    //int heights[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heights[2] = {9,0};

    int max = largestRectangleArea(heights, 2);

    printf("max = %d\n", max);

    return 0;
}

