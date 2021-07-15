#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NOT_SEARCH  0
#define SEARCHING   1
#define SEARCHED    2

int** edge;
int* edgeColSize;
int* visite;
int* stack;
int stack_pointer = 0;
bool valid = true;

void dfs(int v)
{
    visite[v] = SEARCHING;
    for(int i = 0; i < edgeColSize[v]; ++i)
    {
        int next = edge[v][i];
        if(visite[next] == SEARCHING)
        {
            valid = false;
            return;
        }
        else if(visite[next] == NOT_SEARCH)
        {
            dfs(next);
        }
    }
    stack[stack_pointer] = v;
    stack_pointer++;
    visite[v] = SEARCHED;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
{
    if(numCourses == 0 && (prerequisites == NULL || prerequisitesSize <= 0 || prerequisitesColSize == NULL || prerequisitesColSize[0] <= 0))
    {
        *returnSize = 0;
        return NULL;
    }

    edge = (int**)calloc(numCourses, sizeof(int*));
    edgeColSize = (int*)calloc(numCourses, sizeof(int));
    visite = (int*)calloc(numCourses, sizeof(int));
    stack = (int*)calloc(numCourses, sizeof(int));
    stack_pointer = 0;
    valid = true;

    for(int i = 0; i < prerequisitesSize; ++i)
    {
        int head = prerequisites[i][0];
        int tail = prerequisites[i][1];
        edgeColSize[tail]++;
        edge[tail] = (int*)realloc(edge[tail], edgeColSize[tail] * sizeof(int));
        edge[tail][edgeColSize[tail] - 1] = head;
    }

    for(int i = 0; i < numCourses && valid; ++i)
    {
        if(visite[i] == NOT_SEARCH)
        {
             dfs(i);
        }
    }

    int* result = (int*)calloc(numCourses, sizeof(int));
    if(!valid)
    {
        *returnSize = 0;
    }
    else
    {
        *returnSize = 0;
        while(stack_pointer)
        {
            result[*returnSize] = stack[stack_pointer - 1];
            stack_pointer--;
            (*returnSize)++;
        }
    }

    return result;
}

/*
typedef struct LINK_T
{
    int val;
    int pre;
    int next;
} link_node;

void init_link(link_node* vertex, int numCourses, int *no_rely)
{
    *no_rely = 0;
    for(int i = 0; i < numCourses; ++i)
    {
        vertex[i].val = 0;
        vertex[i].next = (i + 1) % numCourses;
        vertex[i].pre = (i + numCourses - 1) % numCourses;
    }
}

void add_link(link_node* vertex, int numCourses, int* rely, int index)
{
    if(index < 0 || index >= numCourses)
    {
        printf("add error.\n");
        exit(0);
    }

    if(*rely == -1)
    {
        *rely = index;
        vertex[index].next = index;
        vertex[index].pre = index;
        vertex[index].val = 1;
    }
    else
    {
        if(vertex[index].val > 0)
        {
            vertex[index].val++;
        }
        else
        {
            vertex[index].next = *rely;
            vertex[index].pre = vertex[*rely].pre;
            vertex[vertex[*rely].pre].next = index;
            vertex[*rely].pre = index;
            vertex[index].val = 1;
        }
    }
}

void del_link(link_node* vertex, int numCourses, int* rely, int index)
{
    if(*rely == -1 || index < 0 || index >= numCourses)
    {
        printf("del error.\n");
        exit(0);
    }

    vertex[vertex[index].pre].next = vertex[index].next;
    vertex[vertex[index].next].pre = vertex[index].pre;
    vertex[index].val = 0;
    if(vertex[index].next == index)
    {
        *rely = -1;
    }
    else if(*rely == index)
    {
        *rely = vertex[index].next;
    }
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
{
    if(numCourses == 0 && (prerequisites == NULL || prerequisitesSize <= 0 || prerequisitesColSize == NULL || prerequisitesColSize[0] <= 0))
    {
        *returnSize = 0;
        return NULL;
    }

    link_node vertex[numCourses];
    int no_rely = -1, rely = -1, head, tail, cur;
    init_link(vertex, numCourses, &no_rely);
    int map[numCourses][numCourses];
    memset(map, 0, numCourses * numCourses * sizeof(int));

    for(int i = 0; i < prerequisitesSize; ++i)
    {
        head = prerequisites[i][0];
        tail = prerequisites[i][1];
        if(vertex[head].val == 0)
        {
            del_link(vertex, numCourses, &no_rely, head);
        }
        add_link(vertex, numCourses, &rely, head);

        map[tail][head] = 1;
    }

    int* ret = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    while(rely != -1)
    {
        if(no_rely == -1)
        {
            // printf("no return.\n");
            free(ret);
            *returnSize = 0;
            return NULL;
        }
        ret[count++] = no_rely;
        cur = no_rely;
        for(int i = 0; i < numCourses; ++i)
        {
            if(map[cur][i])
            {
                vertex[i].val--;
                if(vertex[i].val == 0)
                {
                    del_link(vertex, numCourses, &rely, i);
                    add_link(vertex, numCourses, &no_rely, i);
                }
            }
        }
        del_link(vertex, numCourses, &no_rely, cur);
    }
    while(no_rely != -1)
    {
        ret[count++] = no_rely;
        del_link(vertex, numCourses, &no_rely, no_rely);
    }

    *returnSize = count;
    return ret;
}
*/
