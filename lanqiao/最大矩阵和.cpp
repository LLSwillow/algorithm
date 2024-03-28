#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=1010;
int q[N][N];
int t;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	int maxx=0;
	while(t--)
	{
		int m,n,x,y;
		cin>>m>>n>>x>>y;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>q[i][j];
				q[i][j]+=q[i-1][j]+q[i][j-1]-q[i-1][j-1];
			}
		}
		for(int i=x;i<=m;i++)
		{
			for(int j=y;j<=n;j++)
			{
				maxx=max(maxx,q[i][j]-q[i-x][j]-q[i][j-y]+q[i-x][j-y]);
			}
		}
	}
	cout<<maxx;
	return 0;
}
