#include<iostream>
#include<algorithm>
using namespace std;
const int N=110,INF=0x3f3f3f3f;
int f[N][N],w[N][N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>w[i][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i+1;j++)
        {
            f[i][j]=-INF;
        }
    }
    f[1][1]=w[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j]=w[i][j]+max(f[i-1][j],f[i-1][j-1]);
        }
    }
    if(n%2)cout<<f[n][n/2+1];
    else cout<<max(f[n][n/2],f[n][n/2+1]);
    return 0;
}