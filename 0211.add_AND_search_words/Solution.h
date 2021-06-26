#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <string>
//#include <>

struct DicCharNode{
    char val;
    DicCharNode* left;
    DicCharNode* right;
    bool end;
    DicCharNode(char x) : val(x), left(NULL), right(NULL), end(false) {}
};

class WordDictionary{
public:
    WordDictionary(void);
    void addWord(std::string word);
    bool search(std::string word);
private:
    DicCharNode* root;
    bool searchWithRoot(std::string word, DicCharNode* dicRoot);
    void addWordWithRoot(std::string word, DicCharNode* dicRoot);
};


#endif
