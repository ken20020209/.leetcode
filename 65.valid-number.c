/*
 * @lc app=leetcode id=65 lang=c
 *
 * [65] Valid Number
 */
#include "header\leetcode.h"

// @lc code=start
enum input
{
    sign,
    dot,
    e,
    nums
};
char *trim(char *s)
{
    while (*s == ' ')
        s++;
    char *temp = s;
    while (*temp != '\0')
        temp++;
    while (temp != s && *(--temp) == ' ')
        *temp = 0;
    return s;
}
bool isNumber(char *s)
{
    s = trim(s);
    int len = strlen(s);
    int input;
    int state = 0;
    int stateTalbe[][4] =
        {
            // s  d  e  n
            {1, 3, -1, 2},   // 0
            {-1, 3, -1, 2},  // 1 +/-
            {-1, 8, 5, 2},   // 2 1-9 or +/- 1-9
            {-1, -1, -1, 4}, // 3 .
            {-1, -1, 5, 4},  // 4 . 1-9 or 1-9.1-9 or +/- 1-9.1-9
            {6, -1, -1, 7},  // 5 *e
            {-1, -1, -1, 7}, // 6 *e +/-
            {-1, -1, -1, 7}, // 7 *e +/- 1-9
            {-1, -1, 5, 4},  // 8 1-9 .
        };
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            input = nums;
        else if (s[i] == 'e' || s[i] == 'E')
            input = e;
        else if (s[i] == '.')
            input = dot;
        else if (s[i] == '+' || s[i] == '-')
            input = sign;
        else
            return false;
        state = stateTalbe[state][input];
        // printf("state: %d\n", state);
        if (state == -1)
            return false;
    }
    return (state == 2 || state == 4 || state == 7 || state == 8);
}
// @lc code=end
int main()
{
    return 0;
}