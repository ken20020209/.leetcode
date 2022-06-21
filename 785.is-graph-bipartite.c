/*
 * @lc app=leetcode id=785 lang=c
 *
 * [785] Is Graph Bipartite?
 */
#include "header\leetcode.h"

// @lc code=start
//1 red -1 blue 0 novitis
int dfs(int **g,int s,int *cs,int *c,int n)
{
    int ret=true;
    int cc=c[n];
    /*
    for (int i = 0; i < s; i++)
    {
        printf("% d", c[i]);
    }
    printf("\n");
    */
    for(int i=0;i<cs[n];i++)
    {
        int next=g[n][i];

        if(c[next]==0)
        {
            c[next]=-cc;
            ret= ret && dfs(g,s,cs,c,next);
        }
        else if(c[next]==cc)
        {
            ret=false;
            continue;
        }
        else if(c[next]!=cc)continue;;
        
    }
    return ret;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    int *colors=(int*)calloc(graphSize,sizeof(int));
    //memset(colors, 0, graphSize*sizeof(int));
    
    int res=true;
    for(int i=0;i<graphSize;i++)
    {
        if(colors[i]==0)colors[i]=1;
        res=res&&dfs(graph, graphSize, graphColSize, colors,i);
    }
    free(colors);
    return res;
}
// @lc code=end

