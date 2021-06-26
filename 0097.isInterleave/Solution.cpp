#include "Solution.h"

bool Solution::isInterleave(std::string s1, std::string s2, std::string s3) {
    if(!s1.length())
    {
        return (s2.compare(s3) == 0);
    }
    if(!s2.length())
    {
        return (s1.compare(s3) == 0);
    }
    if(!s3.length())
    {
        return false;
    }

    if(s1[0] == s3[0] && s2[0] != s3[0])
    {
        return isInterleave(s1.substr(1), s2, s3.substr(1));
    }
    if(s1[0] != s3[0] && s2[0] == s3[0])
    {
        return isInterleave(s1, s2.substr(1), s3.substr(1));
    }
    if(s1[0] == s3[0] && s2[0] == s3[0])
    {
        return (isInterleave(s1.substr(1), s2, s3.substr(1)) || 
                isInterleave(s1, s2.substr(1), s3.substr(1)));
    }

    return false;
}