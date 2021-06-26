#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX_INT 0x7fffffff

typedef struct FTree_t {
    int* failure;
    int size;
    struct ListNode** lists;
    int success;
} *FTree;

void FTree_Init_Sort(FTree ftree)
{
    int *failure = ftree->failure;
    struct ListNode** lists = ftree->lists;
    int success[ftree->size];

    for(int i = ftree->size / 2; i < ftree->size; i++)
    {
        success[i] = failure[i];
    }

    for(int i = ftree->size - 1; i > 1; i = i - 2)
    {
        int left = lists[success[i]]->val, right = lists[success[i-1]]->val;
        if(left < right)
        {
            failure[i / 2 - 1] = success[i-1];
            success[i / 2 - 1] = success[i];
        }
        else
        {
            failure[i / 2 - 1] = success[i];
            success[i / 2 - 1] = success[i - 1];
        }
    }

    ftree->success = success[0];
}

/*******************
 *  @param listsSize >= 2
 */
FTree FTree_Init(struct ListNode** lists, int listsSize)
{
    int treeNodeNum = listsSize * 2 - 1;
    int* failure = malloc(treeNodeNum * sizeof(int));

    // put List's first node to failure tree.
    // the first non-leaf node sequence number should be listsSize - 1.
    //   * first node sequence number of failure tree is 0, last is treeNodeNum - 1.
    //              *0 (listsSize = 6)                *0 (listsSize = 5)
    //          *1          *2                    *1       *2
    //      *3      *4    *5   *6               *3   *4  *5   *6
    //    *7  *8  *9  *a                     *7   *8
    for(int i = treeNodeNum - 1; i > listsSize - 2; --i)
    {
        failure[i] = treeNodeNum - i - 1;
    }

    FTree ftree = malloc(sizeof(struct FTree_t));
    ftree->failure = failure;
    ftree->size = treeNodeNum;
    ftree->lists = lists;

    FTree_Init_Sort(ftree);

    return ftree;
}

void FTree_Deinit(FTree ftree)
{
    free(ftree->failure);
    free(ftree);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize < 2)
    {
        return *lists;
    }
    FTree ftree = FTree_Init(lists, listsSize);

    
}

