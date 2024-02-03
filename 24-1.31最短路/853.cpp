#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=510,M=10010;
int n,m,k;
int dist[N],backup[N];
struct Edge{
    int a,b,w;
}edges[M];
int bellmain_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    // k 次迭代可以确保在有限次迭代内 找到从源节点到其他节点的最短路径
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof dist);//每次迭代之前，存好上次dist更新的结果
        for(int j=0;j<m;j++)//对每条边进行松弛操作
        {
            int a=edges[j].a;
            int b=edges[j].b;
            int w=edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);//松弛操作
        }
    }

    if(dist[n]>0x3f3f3f3f/2)return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m>>k;
    /*
    int i=0;
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edges[i++]={x,y,z};
    }*/
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i]={a,b,c};
    }
    int t=bellmain_ford();
    if(t==-1)puts("impossible");
    else cout<<t;
    return 0;
}