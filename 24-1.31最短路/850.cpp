#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>//使用优先队列
using namespace std;
typedef pair<int,int> PII;//第一个元素表示最短距离，第二个元素表示顶点编号
const int N=1.5e5+10;
int n,m;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];//存储从起点到其他节点当前的最短距离
bool st[N];//标记该点是否已经加入到最短路径中

void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);//初始状态所有的距离都是正无穷
    dist[1]=0;//习惯将节点从1开始编号，且本题求的就是1节点到其他节点的最短距离。该点到其自身的距离为0
    priority_queue<PII,vector<PII>,greater<PII>> he;//创建小根堆
    he.push({0,1});//先将源点加入队列

    while(he.size())//当队列不为空
    {
        PII t=he.top();
        he.pop();//将当前的最短距离出队

        int ver=t.second,distance=t.first;//ver表示顶点 distance表示最短距离
        if(st[ver])continue;//如果这个顶点已经处理过就直接跳过
        for(int i=h[ver];i!=-1;i=ne[i])//遍历这个点的所有直连的边
        {
            int j=e[i];
            if(dist[j]>distance+w[i])//更新与其直连的点的最短距离
            {
                dist[j]=distance+w[i];
                he.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    int t=dijkstra();
    cout<<t;
    return 0;
}