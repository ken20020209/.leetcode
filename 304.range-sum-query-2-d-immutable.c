/*
 * @lc app=leetcode id=304 lang=c
 *
 * [304] Range Sum Query 2D - Immutable
 */
#include "header\leetcode.h"

// @lc code=start



typedef struct 
{
    int **dp;
    int r;
    int c;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) 
{
    NumMatrix* obj= (NumMatrix*)malloc(sizeof(NumMatrix));
    obj->r=matrixSize;
    obj->c=*matrixColSize;
    //printf("r:%d c:%d\n", obj->r, obj->c);
    obj->dp=(int**)malloc(obj->r*sizeof(int*));
    for (int i = 0; i < obj->r; i++)
    {
        obj->dp[i]=(int*)calloc(obj->c, sizeof(int));
    }
    //ot
    obj->dp[0][0]=matrix[0][0];
    for(int j=1;j<obj->c;j++)
    {
        obj->dp[0][j]=matrix[0][j]+obj->dp[0][j-1];
    }
    for(int j=1;j<obj->r;j++)
    {
        obj->dp[j][0]=matrix[j][0]+obj->dp[j-1][0];
    }
    for (int i = 1; i < obj->r; i++)
    {
        for(int j =1; j < obj->c; j++)
        {
            int a=obj->dp[i][j-1];
            int b=obj->dp[i-1][j];
            int c=obj->dp[i-1][j-1];
            int d=matrix[i][j];
            obj->dp[i][j]=d+a+b-c;
        }
    }
    /*
    for (int i = 0; i < obj->r; i++)
    {
        for(int j =0; j < obj->c; j++)
        {
            int a=(j-1>=0)?obj->dp[i][j-1]:0;
            int b=(i-1>=0)?obj->dp[i-1][j]:0;
            int c=(i-1>=0&&j-1>=0)?obj->dp[i-1][j-1]:0;
            int d=matrix[i][j];
            if(i==0&&j==1)
            {
                printf("a:%d b:%d c:%d d:%d\n",a,b,c,d);
            }
            obj->dp[i][j]=d+a+b-c;
        }
    }
    */
    
    
    /*
    for (int i = 0; i < obj->r; i++)
    {
        for(int j =0; j < obj->c; j++)
        {
            printf("%d ",obj->dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) 
{
    int d=obj->dp[row2][col2];
    int a=(row1-1>=0&&col1-1>=0)?obj->dp[row1-1][col1-1]:0;
    int b=row1-1>=0?obj->dp[row1-1][col2]:0;
    int c=col1-1>=0?obj->dp[row2][col1-1]:0;
    //printf("a:%d b:%d c:%d d:%d\n",a,b,c,d);
    //printf("%d\n",d-b-c+a);
    return d-b-c+a;
}

void numMatrixFree(NumMatrix* obj) 
{
    for(int i=0; i < obj->r; i++)
    {
        free(obj->dp[i]);
    }
    free(obj->dp);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
// @lc code=end
int main()
{
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int mats=3;
    int matc[]={3,3,3};
    NumMatrix * obj= numMatrixCreate((int**)mat,mats,(int*)matc);
    numMatrixFree(obj);
    return 0;
}