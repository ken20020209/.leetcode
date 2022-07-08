/*
 * @lc app=leetcode id=326 lang=c
 *
 * [326] Power of Three
 */
#include "header\leetcode.h"

// @lc code=start
// loop
// bool isPowerOfThree(int n)
// {
//     if (n > 0)
//         while (n % 3 == 0)
//         {

//             n /= 3;
//         }
//     return n == 1;
// }

// math
// 3^MAX %3^n =0
bool isPowerOfThree(int n)
{
    return n > 0 && 1162261467 % n == 0;
}
// @lc code=end
