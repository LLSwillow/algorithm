#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10,M=N*2;//M代表最大边数

int n,m;
int h[N];//存放顶点集
int e[M],ne[M],idx;//模拟单链表 共享的节点池
bool st[N];//标记搜过的点
//添加一条由a指向b的边
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
//按顶点进行深搜
void dfs(int u)
{
    st[u]=1;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])dfs(j);
    }
}
int main()
{
    memset(h,-1,sizeof h);//将所有链表的头节点均初始化为-1
    add(1, 2);
    add(2, 3);
    dfs(1);//从某个顶点开始深搜
    return 0;
}