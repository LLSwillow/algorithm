#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=10010;
int q[N][N];
int n,r;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>r;
	while(n--)
	{
		int x,y,w;
		cin>>x>>y>>w;
		q[x+1][y+1]+=w;
	}
	for(int i=1;i<=5001;i++)
	{
		for(int j=1;j<=5001;j++)
		{
			q[i][j]+=q[i-1][j]+q[i][j-1]-q[i-1][j-1]; 
		}
	}
	int maxx=0; 
	for(int i=r;i<=5001;i++)
	{
		for(int j=r;j<=5001;j++)
		{
			maxx=max(maxx,q[i][j]-q[i-r][j]-q[i][j-r]+q[i-r][j-r]);
		}
	}
	cout<<maxx;.
	return 0;
}
