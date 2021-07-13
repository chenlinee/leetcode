#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
    // trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
    int my_trips[][3] = {
        {3,2,7},
        {3,7,9},
        {8,3,9}
    };
    int capacity = 11, tripsSize = sizeof(my_trips) / sizeof(my_trips[0]);
    int tripsColSize[tripsSize];
    int* trips[tripsSize];

    for(int i = 0; i < tripsSize; ++i)
    {
        tripsColSize[i] = sizeof(my_trips[i]) / sizeof(my_trips[i][0]);
        trips[i] = my_trips[i];
    }

    int ret = (int)carPooling(trips, tripsSize, tripsColSize, capacity);
    printf("ret = %d\n", ret);

    return 0;
}

