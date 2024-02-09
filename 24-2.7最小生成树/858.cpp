#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510, INF=0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];//存储每一个顶点到 集合(也就是生成树) 的最短距离
bool st[N];
int prime()
{
    memset(dist,0x3f,sizeof dist);
    int ans=0;//记录最小生成树的权值之和

    for(int i=0;i<n;i++)//要加入所有的顶点，因此要循环n次
    {
        int t=-1;
        //选出一个距生成树最短的顶点
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
            {
                t=j;
            }
        }
        if(i && dist[t]==INF)return INF;
        if(i)ans+=dist[t];//第一个顶点权值是0，没必要再加一次，因此存在该if语句
        //选中t之后，比较原来的各个顶点到生成树的距离 与 各顶点与t顶点的权值的大小关系
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],g[t][j]);
        }
        st[t]=1;
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);//无向图的加边
    }
    int t=prime();
    if(t==INF)puts("impossible");
    else cout<<t<<endl;
    return 0;
}