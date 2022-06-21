int visited[1000];
void dfs(int max_x,int max_y,int x, int y)
{
    if (x<0 || y<0||x>=max_x || y>=max_y) return;
    visited[0]=1;//set visited
    dfs(max_x,max_y,x-1, y);
    dfs(max_x,max_y,x+1, y);
    dfs(max_x,max_y,x, y+1);
    dfs(max_x,max_y,x, y-1);
}