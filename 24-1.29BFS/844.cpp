#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;//定义 坐标对
const int N=110;
int n,m;
int g[N][N];//存储二维迷宫
int d[N][N];//存储从起点到达 每个被访问过的位置 的最短路径长度
PII q[N*N];//创建N*N大小的队列，足以容纳整个迷宫的每个位置
int bfs()
{
    int hh=0,tt=0;//定义队头和队尾
    q[0]={0,0};//将起始点存入队列

    memset(d,-1,sizeof d);//初始化迷宫所有的点为-1 表示未被访问过
    d[0][0]=0;//起始点标记为0 表示已访问，并且起始点到(0,0) (也就是其自身)的最短路径长度为0

    //表示在二维坐标系中，某点的四个相邻位置的 偏移量
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    while(hh<=tt)//只要队列中还有 待寻找下一个满足条件的节点 的当前节点时，就继续执行循环
    {
        PII t=q[hh++];//将队头元素出队

        for(int i=0;i<4;i++)
        {
            //由于t是pair类型，可以由.first/.second访问元素(这里元素也就是x y坐标)
            //  由原来的坐标加上偏移量就得出四个方向上的坐标
            int x=t.first+dx[i];
            int y=t.second+dy[i];
            //首先要满足在迷宫大小范围内的可以通过的点(即g为0)，并且未被访问过(保证了最短路)
            if(x>=0 && x<n && y>=0 && y<m && g[x][y]==0 && d[x][y]==-1)
            {
                d[x][y]=d[t.first][t.second]+1;//更新最短路径长度
                q[++tt]={x,y}; //将新位置加入队列
            }
        }
    }

    return d[n-1][m-1];//返回终点的最短路径长度
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }

    printf("%d",bfs());
    return 0;
}