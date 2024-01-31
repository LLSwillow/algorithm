#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,m;
int h[N],e[N],ne[N],idx;
int q[N],d[N];
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int bfs()
{
    int hh=0,tt=0;
    q[0]=1;//将顶点1放入队列作为起始顶点(可以从任何一个顶点开始进行广度优先搜索)
    memset(d,-1,sizeof d);//初始化距离，表示未识别到该点
    d[1]=0;//将顶点1设为0 如果选择的起始顶点不是1，那么对应的 d 数组的下标就应该是所选起始顶点的编号

    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])//遍历该顶点的直连节点
        {
            int j=e[i];
            if(d[j]==-1)//没被搜过
            {
                d[j]=d[t]+1;
                q[++tt]=j;
            }
        }
    }
    return d[n];//由于顶点从1开始计数，因此最后一个点为第n个点的位置
}
int main()
{
    cin>>n>>m;
    memset(h, -1, sizeof h);//初始化头节点数组
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}