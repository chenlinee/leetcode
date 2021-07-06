#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
    // [[1,2], [2,3], [3,4], [1,4], [1,5]]
    int edgesSize = 5, returnSize = -1;
    int edgesColSize[edgesSize];
    int my_edges[5][2] = 
    {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 4},
        {1, 5}
    };

    int* edges[edgesSize];
    for(int i = 0; i < edgesSize; ++i)
    {
        edgesColSize[i] = edgesSize;
        edges[i] = my_edges[i];
    }

    int* ret = findRedundantConnection(edges, edgesSize, edgesColSize, &returnSize);
    if(returnSize == 2)
    {
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    else
    {
        printf("error, returnSize = %d\n", returnSize);
    }

    return 0;
}

