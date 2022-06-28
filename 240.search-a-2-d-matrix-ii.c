/*
 * @lc app=leetcode id=240 lang=c
 *
 * [240] Search a 2D Matrix II
 */
#include "header\leetcode.h"

// @lc code=start
// bs O(nlogm)time
// bool bs(int *arr, int s, int t)
// {
//     int high = s - 1;
//     int low = 0;
//     int mid;
//     while (low <= high)
//     {
//         mid = low + (high - low) / 2;
//         if (arr[mid] == t)
//             return true;
//         else if (arr[mid] < t)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }
//     return false;
// }
// bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
// {
//     for (int i = matrixSize - 1; i >= 0; i--)
//     {
//         if (matrix[i][0] > target)
//             continue;
//         // printf("%d\n",bs(matrix[i], matrixColSize[i], target));
//         if (bs(matrix[i], matrixColSize[i], target))
//             return true;
//     }
//     return false;
// }
//O(m+n) time
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int j = *matrixColSize - 1;
    int i = 0;
    while (i < matrixSize && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
}
// @lc code=end
