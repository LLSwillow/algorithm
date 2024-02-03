#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e5+10;
int n,m;
typedef pair<int,int> PII;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];
void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    st[1]=1;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=0;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=1;
                }
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
    int t=spfa();
    if(t==-1)puts("impossible");
    else cout<<t;
    return 0;
}