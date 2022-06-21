/*
 * @lc app=leetcode id=205 lang=c
 *
 * [205] Isomorphic Strings
 */
#include "header\leetcode.h"

// @lc code=start


bool isIsomorphic(char * s, char * t)
{
    int maps[256]={0};
    int mapt[256]={0};
    int len=strlen(s);
    for (int i=0; i<len; i++)
    {
        if(maps[s[i]]==0)maps[s[i]]=t[i];
        else if(maps[s[i]]!=t[i])return false;
        if(mapt[t[i]]==0)mapt[t[i]]=s[i];
        else if(mapt[t[i]]!=s[i])return false;
    }

    return true;
}
// @lc code=end

