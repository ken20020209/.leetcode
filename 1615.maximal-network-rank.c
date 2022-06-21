/*
 * @lc app=leetcode id=1615 lang=c
 *
 * [1615] Maximal Network Rank
 */
#include "header\leetcode.h"

// @lc code=start

int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize)
{
    int max=INT_MIN;
    int node[100][100]={0};
    int nodecnt[100]={0};
    for(int i=0; i<roadsSize; i++)
    {
        int top=roads[i][1];
        node[roads[i][0]][top]=1;
        nodecnt[roads[i][0]]++;

        top=roads[i][0];
        node[roads[i][1]][top]=1;
        nodecnt[roads[i][1]]++;
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ", node[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    for(int i=0; i<n;i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int temp=nodecnt[i]+nodecnt[j];
            if(node[i][j]==1)
            {
                temp--;
            }
            //printf("i=%d j=%d temp=%d\n",i,j,temp);
            max=fmax(max,temp);
        }
    }
    return max;
}
// @lc code=end

