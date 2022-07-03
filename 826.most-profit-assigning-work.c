/*
 * @lc app=leetcode id=826 lang=c
 *
 * [826] Most Profit Assigning Work
 */
#include "header\leetcode.h"

// @lc code=start

int cmp(int *a, int *b)
{
    return *a - *b;
}

int maxProfitAssignment(int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize)
{
    int res = 0;
    int map[1000001] = {0};
    for (int i = 0; i < difficultySize; i++)
    {
        map[difficulty[i]] = fmax(map[difficulty[i]], profit[i]);
    }
    qsort(difficulty, difficultySize, sizeof(int), cmp);
    for (int i = 1; i < difficultySize; i++)
    {
        if (map[difficulty[i]] <= map[difficulty[i - 1]])
        {
            difficulty[i] = difficulty[i - 1];
        }
    }
    // BF preEND
    //  for (int i = 0; i < workerSize; i++)
    //  {
    //      int max = 0;
    //      for (int j = difficultySize - 1; j >= 0; j--)
    //      {
    //          if (worker[i] >= difficulty[j])
    //          {
    //              max = fmax(max, map[difficulty[j]]);
    //              break;
    //          }
    //      }
    //      res += max;
    //  }
    // BS
    for (int i = 0; i < workerSize; i++)
    {
        int max = 0;
        int high = difficultySize - 1;
        int low = 0;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (worker[i] >= difficulty[mid])
            {
                max = map[difficulty[mid]];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        res += max;
    }
    return res;
}
// @lc code=end
