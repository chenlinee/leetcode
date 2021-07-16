#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    auto wordDictSet = unordered_set <string> ();
    for(auto word : wordDict)
    {
        wordDictSet.insert(word);
    }

    auto dp = vector<bool>(s.size() + 1);
    dp[0] = true;
    for(long unsigned int i = 1; i <= s.size(); ++i)
    {
        for(long unsigned int j = 0; j < i; ++j)
        {
            if(dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
            {
                dp[i] = true;
            }
        }
    }

    return dp[s.size()];
}
/*
unordered_map<string, int>  dict;
unordered_map<string, bool> sub;

bool searchInDick(string s)
{
    for(int i = 0; i < s.length(); ++i)
    {
        string s_tmp = s.substr(0, i + 1);
        cout << s_tmp << endl;
        if(dict.find(s_tmp) != dict.end())
        {
            if(i != s.length() - 1)
            {
                string substr = s.substr(i + 1, s.length() - i - 1);
                if(sub.find(substr) != sub.end())
                {
                    continue;
                }
                if(searchInDick(substr))
                {
                    return true;
                }
                sub[substr] = false;
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    dict.clear();
    sub.clear();
    for(vector<string>::iterator it = wordDict.begin(); it != wordDict.end(); ++it)
    {
        cout << *it << endl;
        dict[*it] = 1;
    }

    return searchInDick(s);
}
*/
