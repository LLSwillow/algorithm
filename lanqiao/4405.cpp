#include<iostream>
#include<algorithm>
using namespace std;
const int N=510;
int q[N][N];
int n,m,k;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>q[i][j];
			q[i][j]+=q[i-1][j]+q[i][j-1]-q[i-1][j-1];
			//cout<<q[i][j]<<" ";
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int z=1;z<=i;z++)
			{
				for(int y=1;y<=j;y++)
				{
					int t=q[i][j]-q[z-1][j]-q[i][y-1]+q[z-1][y-1];
				
					if(t<=k)
					{
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
