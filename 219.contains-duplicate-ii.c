/*
 * @lc app=leetcode id=219 lang=c
 *
 * [219] Contains Duplicate II
 */
#include "header\leetcode.h"

// @lc code=start
#define MAPSIZE 300000
// use arrya hashmap
bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    if (k == 0)
        return false;
    int windowsSize = k + 1;
    int map[MAPSIZE][2] = {0};
    int address;
    if (windowsSize >= numsSize)
    {
        windowsSize = numsSize;
    }
    for (int i = 0; i < windowsSize; i++)
    {
        address = nums[i] % MAPSIZE;
        address = address < 0 ? MAPSIZE / 2 + address : address;
        while (map[address][1] != 0)
        {
            if (map[address][0] == nums[i])
                return true;
            address++;
            address %= MAPSIZE;
        }
        map[address][0] = nums[i];
        map[address][1] = 1;
    }
    for (int i = windowsSize; i < numsSize; i++)
    {
        address = nums[i - windowsSize] % MAPSIZE;
        address = address < 0 ? MAPSIZE / 2 + address : address;
        while (map[address][0] != nums[i - windowsSize])
        {
            address++;
            address %= MAPSIZE;
        }
        map[address][0] = 0;
        map[address][1] = 0;

        address = nums[i] % MAPSIZE;
        address = address < 0 ? MAPSIZE / 2 + address : address;
        while (map[address][1] != 0)
        {
            if (map[address][0] == nums[i])
                return true;
            address++;
            address %= MAPSIZE;
        }
        map[address][0] = nums[i];
        map[address][1] = 1;
    }

    return false;
}
// @lc code=end
