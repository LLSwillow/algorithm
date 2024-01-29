#include<iostream>
using namespace std;
const int N=12;
int n;
char g[N][N];
bool col[N],dg[N],udg[N];

void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
        {
            puts(g[i]);
        }
        puts("");
        return;
    }
    for(int i=0;i<n;i++)
    {
        //相当于u表示每行/i表示列，那么我们想要表示对角线
        if(!col[i] && !dg[u+i] && !udg[n-u+i])
        {
            g[u][i]='Q';//用u来表示行，变化的是第u行中的某个元素
            col[i]=dg[u+i]=udg[n-u+i]=1;
            dfs(u+1);//通过递归确保了每一行放一个皇后
            g[u][i]='.';//恢复现场
            col[i]=dg[u+i]=udg[n-u+i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            g[i][j]='.';
        }
    }
    dfs(0);
    return 0;
}