#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int q[N][N];
int n,m,k;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>q[i][j];
			q[i][j]+=q[i-1][j]+q[i][j-1]-q[i-1][j-1];
		}
	}
	while(k--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<q[x2][y2]-q[x1-1][y2]-q[x2][y1-1]+q[x1-1][y1-1]<<endl;
	}
	return 0;
}
