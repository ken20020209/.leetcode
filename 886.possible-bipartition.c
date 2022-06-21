/*
 * @lc app=leetcode id=886 lang=c
 *
 * [886] Possible Bipartition
 */
#include "header\leetcode.h"

// @lc code=start

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
bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize)
{
    //dislikes is edge
    //convert to graph
    int **graph=(int**)malloc((n+1)*sizeof(int*));
    int *graphSize=(int*)calloc(n+1, sizeof(int));
    //int colors=(int*)calloc(n, sizeof(int));
    int res;
    //printf("%d\n",i);
    for(int i=0; i<n+1; i++)
    {
        graph[i]=(int*)calloc(n>50?n/2:n, sizeof(int));
    }
    for(int i=0; i<dislikesSize; i++)
    {
        //printf("%d\n",i);
        //printf("gs1%d\n",graphSize[dislikes[i][1]]);
        graph[dislikes[i][0]][graphSize[dislikes[i][0]]]=dislikes[i][1];
        graphSize[dislikes[i][0]]++;
        //printf("gs2%d\n",graphSize[dislikes[i][1]]);
        graph[dislikes[i][1]][graphSize[dislikes[i][1]]]=dislikes[i][0];
        graphSize[dislikes[i][1]]++;
    }
    res=isBipartite(graph,n+1,graphSize);
    for(int i=0; i<n; i++)
    {
        free(graph[i]);
    }
    //free(colors);
    free(graph);
    free(graphSize);
    return res;
}
// @lc code=end

