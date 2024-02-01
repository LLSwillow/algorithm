#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510;
int n,m;
int g[N][N];//用邻接矩阵来存储稠密图，二维数组的每一位表示【行标指向列标的边 所对应的权重】
int dist[N];//存储从起点到其他节点当前的最短距离
bool st[N];//标记该点是否已经加入到最短路径中

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);//初始状态所有的距离都是正无穷
    dist[1]=0;
    //习惯将节点从1开始编号，且本题求的就是1节点到其他节点的最短距离。该点到其自身的距离为0

    //确保了寻找了每个节点到源节点的最短路径
    for(int i=0;i<n;i++)
    {
        int t=-1;// 用于标记当前轮次中【距离最短的未访问节点的编号】，初始化为 -1 表示尚未找到有效节点
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
            {
                t=j;//找到当前轮次中距离最短的未访问节点的编号
            }
        }

        if(t==n)break;//t=n说明已经找到了
        
        st[t]=1;//找到后将其标记为1

        //通过选定的节点更新到其他节点的最短距离
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dist[t]+g[t][j]);//g[t][j]表示经过节点t到达节点j的路径长度
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);//面对多重边的情况 取权值小的边
    }

    int t=dijkstra();
    cout<<t;
    return 0;
}