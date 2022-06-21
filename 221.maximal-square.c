/*
 * @lc app=leetcode id=221 lang=c
 *
 * [221] Maximal Square
 */
#include "header\leetcode.h"

// @lc code=start
//O(n^2)
int dp2_maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int m=matrixSize;
    int n=*matrixColSize;
    int max=0;
    int **dp=(int**)malloc(m*sizeof(int*));
    for (int i=0;i<m;i++) 
    {
        dp[i]=(int*)calloc(n,sizeof(int));
    }
    dp[0][0]=matrix[0][0];
    for(int i=1;i<m;i++)
    {
        dp[i][0]=matrix[i][0]-'0';
    }
    for(int i=1;i<n;i++)
    {
        dp[0][i]=matrix[0][i]-'0';
    }
    for(int i=0;i<m;i++)
    {
        if(matrix[i][0]=='1')
        {
            max=1;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(matrix[0][i]=='1')
        {
            max=1;
            break;
        }
    }
    
    for(int i=1; i<m; i++)
    {
        for (int j = 1; j < n; j++)
        {
               if(matrix[i][j]=='1')
               {
                    dp[i][j]=fmin(dp[i-1][j],fmin(dp[i][j-1],dp[i-1][j-1]))+1;
                    if (dp[i][j]>max)max=dp[i][j];                  
               }
        }
    }
    for (int i=0;i<m;i++)
    {
        free(dp[i]);
    }
    free(dp);
    return max*max;
}
//O(n^3)
int dp1_maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int m=matrixSize;
    int n=*matrixColSize;
    int size=0;
    int flag=1;
    //set presum dp
    int **dp=(int**)malloc(m*sizeof(int*));
    for (int i=0;i<m;i++) 
    {
        dp[i]=(int*)calloc(n,sizeof(int));
        for (int j=0;j<n;j++)
        {
            matrix[i][j]-='0';
        }
    }
    dp[0][0]=matrix[0][0];
    for(int i=1;i<m;i++)
    {
        dp[i][0]=matrix[i][0]+dp[i-1][0];
    }
    for(int i=1;i<n;i++)
    {
        dp[0][i]=matrix[0][i]+dp[0][i-1];
    }
    for (int i=1;i<m;i++) 
    {
        for (int j=1;j<n;j++)
        {
            dp[i][j]=matrix[i][j]+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
        }
        
    }
    /*
    for (int i=0;i<m;i++) 
    {
        for (int j=0;j<n;j++)
        {
            printf(" %d ",dp[i][j]);
        }
        printf("\n");
    }
    */
    //serch square
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j]==1)
            {
                flag=1;
                while (i+size<m&&j+size<n&&flag==1)
                {
                    int temp,a,b,c,d;
                    a=dp[i+size][j+size];
                    b=(i-1>=0&&j-1>=0)?dp[i-1][j-1]:0;
                    c=(i-1>=0)?dp[i-1][j+size]:0;
                    d=(j-1>=0)?dp[i+size][j-1]:0;
                    temp=a+b-c-d;
                    //printf("temp:%d size:%d i:%d j:%d \n", temp,size,i,j);
                    if (temp!=(size+1)*(size+1))flag=0;
                    if(flag==1)size++;
                }
                
            }
            
        }
    }
    for (int i=0;i<m;i++)
    {
        free(dp[i]);
    }
    free(dp);
    return size*size;
    
}
//O(n^4)
int bf_maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int m=matrixSize;
    int n=*matrixColSize;
    int size=1;
    int flag=1;
    int res=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j]=='1')
            {
                size=1;
                flag=1;
                while (i+size<m&&j+size<n&&flag==1)
                {
                    for (int  k  = i; k  <= i+size; k ++)
                    {
                        if(matrix[k][j+size]=='0')
                        {
                            flag=0;
                            break;
                        }
                    }
                    for (int  k  = j; k  <= j+size; k ++)
                    {
                        if(matrix[i+size][k]=='0')
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1)
                    {                   
                        size++;
                    }
                }
                if (size>res)res=size;
                if(res>n/2+1||res>m/2+1)return res*res;
            }
            
        }
    }
    return res*res;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    return dp2_maximalSquare(matrix,matrixSize, matrixColSize);
    return dp1_maximalSquare(matrix,matrixSize, matrixColSize);
    return bf_maximalSquare(matrix,matrixSize, matrixColSize);
}
// @lc code=end

