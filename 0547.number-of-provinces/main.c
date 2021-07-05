#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    //int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
    int isConnectedSize = 4;
    int isConnectedColSize[isConnectedSize];
    int my_isConnected[4][4] = {
            {1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}
        };

    int* isConnected[isConnectedSize];
    for(int i = 0; i < isConnectedSize; ++i)
    {
        isConnected[i] = my_isConnected[i];
        isConnectedColSize[i] = isConnectedSize;
    }

    int ret = findCircleNum(isConnected, isConnectedSize, isConnectedColSize);
    printf("ret = %d\n", ret);

    return 0;
}

