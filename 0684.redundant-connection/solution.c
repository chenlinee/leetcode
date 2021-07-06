#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool find(int* vertex, int size, int i, int j)
{
    if(vertex == NULL || i < 1 || j < 1 || i > size || j > size)
    {
        printf("find error. vertex = %p, size = %d, i = %d, j = %d\n",
                vertex, size, i, j);
        exit(0);
    }
    int i_root = i, j_root = j, tmp;
    while(vertex[i_root] != i_root)
    {
        i_root = vertex[i_root];
    }
    for(int m = i; vertex[m] != i_root;)
    {
        tmp = m;
        m = vertex[m];
        vertex[tmp] = i_root;
    }
    while(vertex[j_root] != j_root)
    {
        j_root = vertex[j_root];
    }
    for(int m = j; vertex[m] != j_root;)
    {
        tmp = m;
        m = vertex[m];
        vertex[tmp] = j_root;
    }

    if(i_root == j_root)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void merge(int* vertex, int size, int i, int j)
{
    if(vertex == NULL || i < 1 || j < 1 || i > size || j > size)
    {
        printf("merge error. vertex = %p, size = %d, i = %d, j = %d\n",
                vertex, size, i, j);
        exit(0);
    }
    int i_root = i, j_root = j;
    while(vertex[i_root] != i_root)
    {
        i_root = vertex[i_root];
    }
    while(vertex[j_root] != j_root)
    {
        j_root = vertex[j_root];
    }

    vertex[i_root] = j_root;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    if(edges == NULL || edgesSize < 1 || edgesColSize == NULL || returnSize == NULL || edgesColSize[0] < 1)
    {
        return NULL;
    }

    int vertex[edgesSize + 1];
    for(int i = 1; i < edgesSize + 1; ++i)
    {
        vertex[i] = i;
    }
    int* ret = (int*)calloc(edgesColSize[0], sizeof(int));
    int head, tail;
    for(int i = 0; i < edgesSize; ++i)
    {
        head = edges[i][0];
        tail = edges[i][1];
        if(!find(vertex, edgesSize, head, tail))
        {
            merge(vertex, edgesSize, head, tail);
        }
        else
        {
            ret[0] = head;
            ret[1] = tail;
        }
    }

    *returnSize = 2;
    return ret;
}
