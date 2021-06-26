#include "Solution.h"
#include "stdio.h"

using namespace std;

void ldr(DicCharNode* root)
{
    if(!root)
    {
        return;
    }
    if(root->left)
    {
        ldr(root->left);
    }
    printf("%c", root->val);
    if(root->right)
    {
        ldr(root->right);
    }
}

void dlr(DicCharNode* root)
{
    if(!root)
    {
        return;
    }
    printf("%c", root->val);
    if(root->left)
    {
        dlr(root->left);
    }
    if(root->right)
    {
        dlr(root->right);
    }
}

void printDic(DicCharNode* root)
{
    ldr(root);
    cout << "\t";
    dlr(root);
    cout << "\n";
}

WordDictionary::WordDictionary() {
    this->root = new DicCharNode('R');
}

/** Adds a word into the data structure. */
void WordDictionary::addWord(string word) {
    int len = word.length();
    if(!this->root)
    {
        WordDictionary();
    }
    DicCharNode* node = this->root->left;
    DicCharNode* tmpRoot = this->root;
    for(int i = 0; i < len; ++i)
    {
        char tmpChar = word[i];
        if(node == NULL || tmpChar < node->val)
        {
            DicCharNode* newNode = new DicCharNode(tmpChar);
            newNode->right = tmpRoot->left;
            tmpRoot->left = newNode;

            node = newNode->left;
            tmpRoot = newNode;
            continue;
        }

        while(node != NULL)
        {
            if(tmpChar == node->val)
            {
                tmpRoot = node;
                node = node->left;
                break;
            }
            if(node->right == NULL || tmpChar < node->right->val)
            {
                DicCharNode* newNode = new DicCharNode(tmpChar);
                newNode->right = node->right;
                node->right = newNode;

                node = newNode->left;
                tmpRoot = newNode;
                break;
            }
            tmpRoot = node;
            node = node->right;
        }
    }
    tmpRoot->end = true;

    printDic(this->root);
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool WordDictionary::search(string word) {
    if(this->root == NULL)
    {
        return false;
    }
    int len = word.length();
    DicCharNode* node = this->root->left;
    if(node == NULL)
    {
        return false;
    }
    if(word[0] != '.')
    {
        if(word[0] < node->val)
        {
            return false;
        }
        if(word[0] == node->val)
        {
            if(len == 1 && node->end)
            {
                return true;
            }
            string tmpWord = word.substr(1);
            return searchWithRoot(tmpWord, node->left);
        }
        if(word[0] > node->val)
        {
            return searchWithRoot(word, node->right);
        }
    }
    else
    {
        if(len == 1)
        {
            while(node)
            {
                if(node->end)
                {
                    return true;
                }
                node = node->right;
            }
            return false;
        }
        string tmpWord = word.substr(1);
        while(node)
        {
            if(searchWithRoot(tmpWord, node->left))
            {
                return true;
            }
            node = node->right;
        }
        return false;
    }

    return false;
}

bool WordDictionary::searchWithRoot(string word, DicCharNode* dicRoot)
{
    if(dicRoot == NULL)
    {
        return false;
    }
    int len = word.length();
    if(word[0] != '.')
    {
        if(word[0] < dicRoot->val)
        {
            return false;
        }
        if(word[0] == dicRoot->val)
        {
            if(len == 1 && dicRoot->end)
            {
                return true;
            }
            string tmpWord = word.substr(1);
            return searchWithRoot(tmpWord, dicRoot->left);
        }
        if(word[0] > dicRoot->val)
        {
            return searchWithRoot(word, dicRoot->right);
        }
    }
    else
    {
        if(len == 1)
        {
            while(dicRoot)
            {
                if(dicRoot->end)
                {
                    return true;
                }
                dicRoot = dicRoot->right;
            }
            return false;
        }
        string tmpWord = word.substr(1);
        while(dicRoot)
        {
            if(searchWithRoot(tmpWord, dicRoot->left))
            {
                return true;
            }
            dicRoot = dicRoot->right;
        }
        return false;
    }

    return false;
}
/*
bool search(string word) {
    int len = word.length();
    if(!root)
    {
        return false;
    }
    DicCharNode* node = this->root->left;
    DicCharNode* nodeFather = this->root;
    stack<stack<pair<DicCharNode*, int>>> tmpSearch;
    for(int i = 0; i < len; ++i)
    {
        if(node == NULL)
        {
            return false;
        }
        if(word[i] == '.')
        {
            stack<pair<DicCharNode*, int>> tmpStack;
            tmpStack.push(make_pair(node, i));
            tmpSearch.push(tmpStack);
            nodeFather = node;
            node = node->left;
            continue;
        }
        if(word[i] < node->val)
        {
            stack<pair<DicCharNode*, int>> pStack;
            pair<DicCharNode*, int> p;
            while(!tmpSearch.empty())
            {
                pStack = tmpSearch.top();
                if(pStack.empty())
                {
                    return false;
                }
                p = pStack.top();
                node = p.first->right;
                if(node == NULL)
                {
                    tmpSearch.pop();
                }
                else
                {
                    break;
                }
            }
            if(tmpSearch.empty())
            {
                return false;
            }
            nodeFather = node;
            node = node->left;
            pStack.pop();
            i = p.second;
            pStack.push(make_pair(nodeFather, i));
            continue;
        }
        if(word[i] == node->val)
        {
            nodeFather = node;
            node = node->left;
            continue;
        }
        for(node = node->right; node; node = node->right)
        {
            if(word[i] == node->val)
            {
                break;
            }
        }
        if(node == NULL)
        {
            stack<pair<DicCharNode*, int>> pStack;
            pair<DicCharNode*, int> p;
            while(!tmpSearch.empty())
            {
                pStack = tmpSearch.top();
                if(pStack.empty())
                {
                    return false;
                }
                p = pStack.top();
                node = p.first->right;
                if(node == NULL)
                {
                    tmpSearch.pop();
                }
                else
                {
                    break;
                }
            }
            if(tmpSearch.empty())
            {
                return false;
            }
            nodeFather = node;
            node = node->left;
            pStack.pop();
            i = p.second;
            pStack.push(make_pair(nodeFather, i));
            continue;
        }
        else
        {
            nodeFather = node;
            node = node->left;
            continue;
        }
    }

    if(!nodeFather->end)
    {
        return false;
    }
    return true;
}
*/

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
