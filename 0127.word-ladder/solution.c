#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 0x00FFFFFF

int wordLen = 0;
unsigned int** martrix;

bool isLink(char* a, char* b, int len)
{
    if(a == NULL || b == NULL || len < 1)
    {
        return false;
    }
    int count = 0;
    for(int i = 0; i < len; ++i)
    {
        if(a[i] != b[i])
        {
            count++;
        }
    }

    return count == 1 ? true : false;
}

void initMartrix(char** wordList, int wordListSize, char* beginWord)
{
    for(int i = 0; i < wordListSize + 1; ++i)
    {
        for(int j = i + 1; j < wordListSize + 1; ++j)
        {
            if(i == 0)
            {
                if(isLink(beginWord, wordList[j - 1], wordLen))
                {
                    martrix[i][j] = 1;
                    martrix[j][i] = 1;
                }
            }
            else
            {
                if(isLink(wordList[i - 1], wordList[j - 1], wordLen))
                {
                    martrix[i][j] = 1;
                    martrix[j][i] = 1;
                }
            }
        }
    }
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    if(beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize < 1)
    {
        return 0;
    }

    wordLen = 0;
    while(beginWord[wordLen] != 0) ++wordLen;
    int target = -1;
    for(int i = 0, j = 0; i < wordListSize; ++i)
    {
        for(j = 0; j < wordLen; ++j)
        {
            if(wordList[i][j] != endWord[j]) {break;}
        }
        if(j == wordLen) {target = i + 1;}
    }
    if(target == -1) {return 0;}

    martrix = (unsigned int**)calloc(wordListSize + 1, sizeof(unsigned int*));
    for(int i = 0; i < wordListSize + 1; ++i)
    {
        martrix[i] = (unsigned int*)malloc((wordListSize + 1) * sizeof(unsigned int));
        for(int j = 0; j < wordListSize + 1; ++j)
        {
            martrix[i][j] = MAX;
        }
    }
    initMartrix(wordList, wordListSize, beginWord);

    int visite[wordListSize + 1];
    memset(visite, 0, (wordListSize + 1) * sizeof(int));
    visite[0] = 1;
    for(int i = 0; i < wordListSize + 1; ++i)
    {
        int k = 0;
        for(int j = 0; j < wordListSize + 1; ++j)
        {
            if(!visite[j] && (k == 0 || martrix[0][j] < martrix[0][k]))
            {
                k = j;
            }
        }
        visite[k] = 1;
        for(int j = 0; j <= wordListSize + 1; ++j)
        {
            if(!visite[j] && martrix[0][k] + martrix[k][j] < martrix[0][j])
            {
                martrix[0][j] = martrix[0][k] + martrix[k][j];
            }
        }
    }

    int ret = martrix[0][target];
    martrix = (unsigned int**)calloc(wordListSize + 1, sizeof(unsigned int*));
    for(int i = 0; i < wordListSize + 1; ++i)
    {
        free(martrix[i]);
    }
    free(martrix);
    return ret < MAX ? ret + 1 : 0;
}
