/*
 * @lc app=leetcode id=1557 lang=c
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */
#include "header\leetcode.h"

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int i=0;
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    if(i++==50)return 0;
    *returnSize =0;
    int *res=calloc(n,sizeof(int));
    int *map=(int*)malloc(n*sizeof(int));
    memset(map,0,n*sizeof(int));
    for(int i=0; i<edgesSize; i++)
    {
        map[edges[i][1]]=1;
    }
    for (int i = 0; i < n; i++)
    {
        if(map[i]==0)
        {
            res[*returnSize]=i;
            (*returnSize)++;
        }
    }
    
    return res;
}
// @lc code=end
int main()
{
    int n;
    int**edges;
    int edgesSize;
    int *edgesColSize;
    int returnSize;
    char **str=readtestcase();

    n=stoi(str[0]);
    edges=stoiaa(str[1],&edgesSize,&edgesColSize);

    int *res=findSmallestSetOfVertices( n, edges, edgesSize,  edgesColSize,  &returnSize);
    printf("[");
    for (int i=0; i <returnSize; i++)
    {
        printf(" %d ",res[i]);
    }
    printf("]\n");
    return 0;
}