#ifndef SOLUTION_H
#define SOLUTION_H

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);


#endif
