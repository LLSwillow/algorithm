#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,m;
int h[N],e[N],ne[N],idx;
int q[N],d[N];//d数组此时表示的是每个顶点的入度
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool topsort()
{
    int hh=0,tt=-1;//表示队头 队尾的指针

    for(int i=1;i<=n;i++)//顶点用1-n表示
    {
        if(!d[i])q[++tt]=i;//入度为0就入队
    }
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])//遍历邻接顶点
        {
            int j=e[i];
            d[j]--;
            if(d[j]==0)q[++tt]=j;//删除顶点之后，若有顶点由此入度变为0，入队
        }
    }
    return tt==n-1;//当队列尾部的计数与顶点数相同时说明找到了一个拓扑排序

}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);//初始化邻接表的顶点集

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        d[y]++;//边由x指向y，y的入度要++
    }

    if(topsort())
    {
        for(int i=0;i<n;i++)
        {
            cout<<q[i]<<" ";
        }
    }
    else cout<<"-1"<<endl;
    return 0;
}