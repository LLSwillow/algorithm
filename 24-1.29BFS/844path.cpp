#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
const int N=120;
int n,m;
int g[N][N],d[N][N];
PII q[N*N],p[N][N];
int bfs()
{
    int hh=0,tt=0;
    q[0]={0,0};

    memset(d,-1,sizeof d);
    d[0][0]=0;

    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    while(hh<=tt)
    {
        PII t=q[hh++];

        for(int i=0;i<4;i++)
        {
            int x=t.first+dx[i];
            int y=t.second+dy[i];

            if(x>=0 && x<n && y>=0 && y<m && d[x][y]==-1 && g[x][y]==0)
            {
                d[x][y]=d[t.first][t.second]+1;
                p[x][y]=t;
                q[++tt]={x,y};
            }
        }
    }
    int x=n-1,y=m-1;
    while(x||y)
    {
        cout<<x<<" "<<y<<endl;
        auto t=p[x][y];
        x=t.first,y=t.second;
    }
    return d[n-1][m-1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    cout<<bfs()<<endl;
    return 0;
}