#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
    // 4, [[1,0],[2,0],[3,1],[3,2]]
    int my_prerequisites[][2] = {
        {1,0},
        {2,0},
    };
    int numCourses = 5, prerequisitesSize = sizeof(my_prerequisites) / sizeof(my_prerequisites[0]), returnSize = -1;
    int prerequisitesColSize[prerequisitesSize];
    int* prerequisites[prerequisitesSize];

    for(int i = 0; i < prerequisitesSize; ++i)
    {
        prerequisites[i] = my_prerequisites[i];
        prerequisitesColSize[i] = sizeof(my_prerequisites[i]) / sizeof(my_prerequisites[i][0]);
    }

    int* ret = findOrder(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize, &returnSize);
    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", ret[i]);
    }
    printf("\n");

    return 0;
}

