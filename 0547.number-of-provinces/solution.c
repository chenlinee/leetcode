#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * if i and j belong to one set, return true;
 * else return false.
 **/ 
bool find(int* arr, int size, int i, int j)
{
    if(arr == NULL || i < 0 || j < 0 || i >= size || j >=size)
    {
        printf("out of array range.\n");
        exit(0);
    }
    int i_parrent = arr[i], j_parrent = arr[j], tmp;
    while(i_parrent != arr[i_parrent])
    {
        i_parrent = arr[i_parrent];
    }
    for(int m = i; arr[m] != i_parrent;)
    {
        tmp = m;
        m = arr[m];
        arr[tmp] = i_parrent;
    }
    while(j_parrent != arr[j_parrent])
    {
        j_parrent = arr[j_parrent];
    }
    for(int m = i; arr[m] != i_parrent;)
    {
        tmp = m;
        m = arr[m];
        arr[tmp] = i_parrent;
    }

    if(i_parrent == j_parrent)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void merge(int* arr, int size, int i, int j)
{
    if(arr == NULL || i < 0 || j < 0 || i >= size || j >=size)
    {
        printf("out of array range.\n");
        exit(0);
    }
    int i_parrent = arr[i], j_parrent = arr[j];
    while(i_parrent != arr[i_parrent])
    {
        i_parrent = arr[i_parrent];
    }
    while(j_parrent != arr[j_parrent])
    {
        j_parrent = arr[j_parrent];
    }
    arr[j_parrent] = i_parrent;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    if(isConnected == NULL || isConnectedSize < 1 || isConnectedColSize[0] < 1)
    {
        return 0;
    }

    int ret = isConnectedSize;
    int arr[isConnectedSize];
    for(int i = 0; i < isConnectedSize; ++i)
    {
        arr[i] = i;
    }
    for(int i = 0; i < isConnectedSize; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(isConnected[i][j] == 1 && !find(arr, isConnectedSize, i, j))
            {
                merge(arr, isConnectedSize, i, j);
                ret--;
            }
        }
    }

    return ret;
}
/*
typedef struct line_array_struct
{
    int value;
    int next;
    int front;
} line_array_t;

void visite(line_array_t* arr, int target, int size)
{
    if(arr[size].value <= 0 || target >= size || target < 0)
    {
        printf("visite %d\n", target);
        return;
    }
    if(target == arr[size].next)
    {
        if(arr[size].value == 1)
        {
            arr[target].value = 1;
            arr[size].next = size;
            arr[size].front = size;
        }
        else
        {
            arr[target].value = 1;
            arr[arr[target].next].front = arr[target].front;
            arr[arr[target].front].next = arr[target].next;
            arr[size].next = arr[target].next;
        }
    }
    else
    {
        arr[target].value = 1;
        arr[arr[target].next].front = arr[target].front;
        arr[arr[target].front].next = arr[target].next;
    }
    arr[size].value--;
}

int getNotVisted(line_array_t* arr, int size)
{
    if(arr[size].value == 0)
    {
        return -1;
    }
    else
    {
        return arr[size].next;
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    if(isConnected == NULL || isConnectedSize < 1 || isConnectedColSize[0] < 1)
    {
        return 0;
    }

    // init vertex array
    line_array_t visited[isConnectedSize + 1];
    for(int i = 0; i < isConnectedSize; ++i)
    {
        visited[i].value = 0;
        visited[i].next = (i + 1) % isConnectedSize;
        visited[i].front = (i + isConnectedSize - 1) % isConnectedSize;
    }
    visited[isConnectedSize].next = 0;
    visited[isConnectedSize].value = isConnectedSize;

    // dfs
    int vertex;
    int stack[isConnectedSize];
    memset(stack, 0, isConnectedSize * sizeof(int));
    int count = 0, ret = 0;
    while((vertex = getNotVisted(visited, isConnectedSize)) != -1)
    {
        ret++;
        count = 0;
        stack[count] = vertex;
        count++;
        visite(visited, vertex, isConnectedSize);
        while(count > 0)
        {
            count--;
            vertex = stack[count];
            for(int i = 0; i < isConnectedSize; ++i)
            {
                if(isConnected[vertex][i] == 1 && visited[i].value == 0)
                {
                    visite(visited, i, isConnectedSize);
                    stack[count] = i;
                    count++;
                }
            }
        }
    }
    return ret;
}
*/