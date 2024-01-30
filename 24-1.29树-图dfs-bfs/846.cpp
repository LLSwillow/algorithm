#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10,M=2*N;
int n;
int h[N];
int e[M],ne[M],idx;
bool st[N];
int ans=N;//用于存储最终结果，由于求的是最小值，我们将其初始值设为最大
//添加一条由a指向b的边
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dfs(int u)//搜索顶点u
{
    st[u]=1;//将u标记为已访问

    int sum=1,res=0;//sum记录以u为根的子树的大小,res记录去掉u后，剩下的各部分中最大的那部分的大小
    for(int i=h[u];i!=-1;i=ne[i])//遍历u的所有邻接节点
    {
        int j=e[i];
        if(!st[j])
        {
            int s=dfs(j);//每求出一个邻接节点所对子树的顶点个数，也就是得到了该连通块中的顶点数
            res=max(res,s);
            sum+=s;//不断累加顶点u所对的各个子树的顶点之和，也就得到了以u为根节点的子树的定点数之和
        }
    }
    res=max(res,n-sum);//那么n-sum表示的就是最后一个连通块中所含顶点数

    ans=min(res,ans);//每求出一个res就直接更新ans 判断最小值
    return sum;
}
int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++)//n个顶点其实只要加n-1条边
    {
        int a,b;
        cin>>a>>b;
        //这里是无向图，两个顶点对应都要加
        add(a,b);
        add(b,a);
    }

    dfs(1);

    cout<<ans<<endl;
    return 0;
}