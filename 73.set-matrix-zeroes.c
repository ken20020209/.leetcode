/*
 * @lc app=leetcode id=73 lang=c
 *
 * [73] Set Matrix Zeroes
 */
#include "header\leetcode.h"

// @lc code=start

//O(1) space 
void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int m=matrixSize;
    int n=*matrixColSize;
    int fc=0;
    int fr=0;
    //check first column set flag
    for (int i = 0; i < m; i++)
    {
         if(matrix[i][0]==0)
         {
            fr=1;
            break;
         }
    }
    //check first row set flag
    for (int i = 0; i < n; i++)
    {
         if(matrix[0][i]==0)
         {
            fc=1;
            break;
         }
    }
    //set matrix==0 (row0 col0 to 0)
    for (int i = 0; i < m; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j] =0;
                matrix[i][0] =0;
            }
        }
    }
    //if  col0 ==0 set that row 0000000
    for (int i = 1; i < m; i++)
    {
        if(matrix[i][0]==0)
        {
            
            for (int j = 0; j < n; j++)
            {
                matrix[i][j]=0;
            }    
        }
    }
    //if  row0 ==0 set that col 0000000
    for (int i = 1; i < n; i++)
    {
        if(matrix[0][i]==0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[j][i]=0;
            }    
        }
    } 
    //set first column to 0
    if(fr)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0]=0;
        }
    }
    //set first row to 0
    if(fc)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j]=0;
        }
        
    }
    
}
// @lc code=end
