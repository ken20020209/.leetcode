/*
 * @lc app=leetcode id=860 lang=c
 *
 * [860] Lemonade Change
 */
#include "header\leetcode.h"

// @lc code=start

bool lemonadeChange(int *bills, int billsSize)
{
    int ten = 0;
    int five = 0;
    int twenty = 0;
    for (int i = 0; i < billsSize; i++)
    {
        if (bills[i] == 5)
        {
            five++;
        }
        else if (bills[i] == 10)
        {
            if (five == 0)
                return false;
            ten++;
            five--;
        }
        else if (bills[i] == 20)
        {
            if (ten != 0)
            {
                ten--;
                if (five == 0)
                    return false;
                five--;
            }
            else
            {
                if (five < 3)
                    return false;
                five -= 3;
            }
        }
    }
    return true;
}
// @lc code=end
