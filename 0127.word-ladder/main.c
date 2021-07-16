#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize)
    //"leet"
    //"code"
    //["lest","leet","lose","code","lode","robe","lost"]
    char my_wordList[][5] = {
        "lest","leet","lose","code","lode","robe","lost"
    };
    char beginWord[] = "leet", endWord[] = "code";
    int wordListSize = sizeof(my_wordList) / sizeof(my_wordList[0]);
    char* wordList[wordListSize];
    for(int i = 0; i < wordListSize; ++i)
    {
        wordList[i] = my_wordList[i];
    }

    printf("ret = %d\n", ladderLength(beginWord, endWord, wordList, wordListSize));

    return 0;
}

