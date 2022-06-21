/*
 * @lc app=leetcode id=365 lang=c
 *
 * [365] Water and Jug Problem
 */
#include "header\leetcode.h"

// @lc code=start


bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
    if(targetCapacity>jug1Capacity+jug2Capacity)return false;
    if(targetCapacity==jug1Capacity+jug2Capacity||targetCapacity==jug2Capacity||targetCapacity==jug1Capacity)return true;
    
    return targetCapacity%gcd(jug1Capacity,jug2Capacity)==0;
}
int gcd(int x, int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
// @lc code=end

