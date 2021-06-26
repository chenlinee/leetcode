#include <stdio.h>
#include "solution.h"
#include "stdlib.h"
#include <string.h>


void init_Lists(int a[][10], struct ListNode *list_p[], int *listsSize)
{
    for(int row = 0; row < 10; ++row)
    {
        struct ListNode *p = NULL;
        for(int col = 0; col < 10; ++col)
        {
            if(col == 0)
            {
                if(a[row][col] < 0)
                {
                    list_p[row] = NULL;
                    *listsSize = row;
                    return;
                }
                list_p[row] = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = list_p[row];
                p->val = a[row][col];
                p->next = NULL;
                continue;
            }
            if(a[row][col] >= 0)
            {
                p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = p->next;
                p->val = a[row][col];
                p->next = NULL;
            }
            else
            {
                break;
            }
        }
    }
}

void print_list(struct ListNode* list_p[])
{
    printf("[");
    for(int i = 0; i < 10; ++i)
    {
        printf("[");
        for(struct ListNode* p = list_p[i]; p != NULL; p = p->next)
        {
            printf("%d", p->val);
            if(p->next != NULL)
            {
                printf(", ");
            }
        }
        if(i == 9 || list_p[i + 1] == NULL)
        {
            printf("]");
            break;
        }
        else
        {
            printf("], ");
        }
    }
    printf("]\n");
}

int main(){
    int a[10][10] = {
        {-1},
        {-1},
        {-1},
        {-1}
    };

    struct ListNode* lists[10];
    for(int i = 0; i < 10; ++i)
    {
        lists[i] = NULL;
    }
    int listsSize = 10;

    //init_Lists(a, lists, &listsSize);
    
    print_list(lists);

    struct ListNode *ret = mergeKLists(lists, listsSize);

    printf("ret: [");
    for(;ret != NULL; ret = ret->next)
    {
        printf("%d", ret->val);
        if(ret->next != NULL)
        {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}

