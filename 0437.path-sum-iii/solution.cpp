#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unordered_map>

using namespace std;

int count = 0;
int sum = 0;

void dlr(TreeNode* root, int targetSum, unordered_map<int, int> *hmap)
{
    if(root == NULL)
    {
        return;
    }
    sum += root->val;
    if(hmap->find(sum - targetSum) != hmap->end())
    {
        count += (*hmap)[sum - targetSum];
    }
    (*hmap)[sum]++;
    dlr(root->left, targetSum, hmap);
    dlr(root->right, targetSum, hmap);
    (*hmap)[sum]--;
    if((*hmap)[sum] == 0)
    {
        hmap->erase(sum);
    }
    sum -= root->val;
}

int pathSum(TreeNode* root, int targetSum) {
    unordered_map<int, int> hmap;
    hmap[0] = 1;
    count = 0;
    sum = 0;

    dlr(root, targetSum, &hmap);

    return count;
}

