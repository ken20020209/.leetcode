/*
 * @lc app=leetcode id=1870 lang=c
 *
 * [1870] Minimum Speed to Arrive on Time
 */
#include "header\leetcode.h"

// @lc code=start

double ntime(int *dist, int distSize, int speed)
{
    double res = 0;
    for (int i = 0; i < distSize - 1; i++)
    {
        res += ceil((double)dist[i] / (double)speed);
    }
    res += (double)dist[distSize - 1] / (double)speed;
    return res;
}
int minSpeedOnTime(int *dist, int distSize, double hour)
{
    int high = 10000000;
    int low = 1;
    int res = -1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        double curtime = ntime(dist, distSize, mid);
        printf("curtime:%d\n", curtime);
        if (curtime == hour)
        {
            return mid;
        }
        else if (curtime < hour)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
// @lc code=end
