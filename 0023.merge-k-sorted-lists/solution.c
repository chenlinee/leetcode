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

#define NULL_LIST -1

typedef struct FTree_t {
    int* failure;
    int size;
    struct ListNode** lists;
    int success;
} *FTree;

void FTree_Sort(FTree ftree)
{
    int *failure = ftree->failure;
    struct ListNode** lists = ftree->lists;

    int success_pos = ftree->success + ftree->size / 2;

    printf("lists[ftree->success] = %p\n", lists[ftree->success]);
    if(lists[ftree->success] == NULL)
    {
        failure[success_pos] = NULL_LIST;
    }
    for(int i = success_pos; i > 0; i = (i - 1) / 2)
    {
        // 父节点队列空，继续往上走
        if(failure[(i - 1) / 2] == NULL_LIST)
        {
            continue;
        }
        // 自己队列空，让父节点往上走
        if(failure[success_pos] == NULL_LIST)
        {
            ftree->success = failure[(i - 1) / 2];
            success_pos = ftree->success + ftree->size / 2;
            failure[(i - 1) / 2] = NULL_LIST;
            continue;
        }
        // 两者都不为空，开始比较
        int root = lists[failure[(i - 1) / 2]]->val;
        int success = lists[ftree->success]->val;
        if(root <= success)
        {
            int pre_success = ftree->success;
            ftree->success = failure[(i - 1) / 2];
            success_pos = ftree->success + ftree->size / 2;
            failure[(i - 1) / 2] = pre_success;
        }
    }
}

void FTree_Init_Sort(FTree ftree)
{
    int *failure = ftree->failure;
    struct ListNode** lists = ftree->lists;
    int success[ftree->size];

    // copy leaf node to success tree
    // check if any list is empty
    for(int i = ftree->size / 2; i < ftree->size; i++)
    {
        success[i] = failure[i];

    }

    int left, right;
    for(int i = ftree->size - 1; i > 1; i = i - 2)
    {
        if(success[i-1] == NULL_LIST)
        {
            failure[i / 2 - 1] = success[i-1];
            success[i / 2 - 1] = success[i];

            continue;
        }
        if(success[i] == NULL_LIST) 
        {
            failure[i / 2 - 1] = success[i];
            success[i / 2 - 1] = success[i - 1];
            continue;
        }
        
        left = lists[success[i]]->val;
        right = lists[success[i-1]]->val;
        if(left <= right)
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
    int* failure = (int *)malloc(treeNodeNum * sizeof(int));

    // * put List's first node to failure tree.
    // * the first non-leaf node sequence number should be listsSize - 1.
    //    * first node sequence number of failure tree is 0, last is treeNodeNum - 1.
    //                *0 (listsSize = 6)                *0 (listsSize = 5)
    //            *1          *2                    *1       *2
    //        *3      *4    *5   *6               *3   *4  *5   *6
    //      *7  *8  *9  *a                     *7   *8
    // * check if any list is empty
    for(int i = treeNodeNum / 2; i < treeNodeNum; ++i)
    {
        if(lists[i - treeNodeNum / 2] != NULL)
        {
            failure[i] = i - treeNodeNum / 2;
        }
        else
        {
            failure[i] = NULL_LIST;
        }
    }

    FTree ftree = (FTree)malloc(sizeof(struct FTree_t));
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
    if(listsSize == 0)
    {
        return NULL;
    }
    if(listsSize == 1)
    {
        return *lists;
    }
    FTree ftree = FTree_Init(lists, listsSize);

    struct ListNode *ret = NULL, *current = NULL;
    while(ftree->success != NULL_LIST && lists[ftree->success] != NULL)
    {
        struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        printf("success = %d\n", ftree->success);
        new_node->val = lists[ftree->success]->val;
        new_node->next = NULL;
        if(ret == NULL)
        {
            ret = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = current->next;
        }

        lists[ftree->success] = lists[ftree->success]->next;
        FTree_Sort(ftree);
    }

    return ret;
}

