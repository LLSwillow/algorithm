#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10,M=2e5+10;
int n,m;
int h[N],e[M],ne[M],idx;
int color[N];//用俩标记是否被染色
void add(int x,int y)
{
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}
bool dfs(int u,int c)//c表示该点被染的颜色
{
    color[u]=c;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!color[j])
        {
            if(!dfs(j,3-c))return 0;
        }
        else if(color[j]==c)return 0;
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);//无向图
        add(v,u);
    }
    bool flag=1;//作为标记
    for(int i=1;i<=n;i++)//遍历所有顶点
    {
        if(!color[i])//如果该点没有被染色
        {
            if(!dfs(i,1))//就通过dfs将其染色，并判断染色是否存在冲突
            {
                flag=0;
                break;
            }
        }
    }
    if(flag)puts("Yes");
    else puts("No");
    return 0;
}