/*
 * @lc app=leetcode id=997 lang=c
 *
 * [997] Find the Town Judge
 */
#include "header\leetcode.h"

// @lc code=start


int findJudge(int n, int** trust, int trustSize, int* trustColSize)
{
    int map[n+1];
    memset(map, 0, (n+1) * sizeof(int));
    for (int i = 0; i < trustSize; i++)
    {
            map[trust[i][0]]--;
            map[trust[i][1]]++;
        
    }
    for(int i = 1; i < n+1; i++)
    {
        printf("%d\n",map[i]);
        if(map[i]==n-1)return i;
    }
    return -1;

}
// @lc code=end

