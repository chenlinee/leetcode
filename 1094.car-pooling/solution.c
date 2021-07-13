#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int delta[1001];
    memset(delta, 0, 1001 * sizeof(int));

    for(int i = 0; i < tripsSize; ++i)
    {
        delta[trips[i][1]] += trips[i][0];
        delta[trips[i][2]] -= trips[i][0];
    }

    for(int i = 0; i < 1001; ++i)
    {
        capacity -= delta[i];
        if(capacity < 0)
        {
            return false;
        }
    }

    return true;
}

/*
int up_sort(const void* eleA, const void* eleB)
{
    return ((int**)eleA)[0][1] - ((int**)eleB)[0][1];
}

int down_sort(const void* eleA, const void* eleB)
{
    return ((int*)eleA)[2] - ((int*)eleB)[2];
}

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    if(trips == NULL || tripsSize == 0 || tripsColSize == NULL || tripsColSize[0] == 0)
    {
        return true;
    }

    int trips_down[tripsSize][tripsColSize[0]];
    for(int i = 0; i < tripsSize; ++i)
    {
        memcpy(trips_down[i], trips[i], tripsColSize[i] * sizeof(int));
    }

    qsort(trips, tripsSize, sizeof(int*), up_sort);
    qsort(trips_down, tripsSize, tripsColSize[0] * sizeof(int), down_sort);

    for(int i = 0, j = 0; i < tripsSize; ++i)
    {
        while(j < tripsSize && trips[i][1] >= trips_down[j][2])
        {
            capacity += trips_down[j][0];
            ++j;
        }
        capacity -= trips[i][0];
        if(capacity < 0)
        {
            return false;
        }
    }
    return true;
}
*/
