/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 */
#include "header\leetcode.h"

// @lc code=start

bool isPalindrome(char *s)
{
    int len = strlen(s);
    int left = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            s[left] = s[i];
            if (i != left)
                s[i] = 0;
            left++;
        }
        else
        {
            s[i] = 0;
        }
    }
    len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    // printf("len = %d\n", len);
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
        {
            return false;
        }
    }
    // printf("%s\n", s);
    return true;
}
// @lc code=end
