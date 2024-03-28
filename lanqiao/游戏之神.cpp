#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e5+10;
int q[N];
int n,k;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
		q[i]+=q[i-1];
	}
	while(k--)
	{
		int f,t;
		cin>>f>>t;
		cout<<q[t]-q[f-1]<<endl;
	}
	return 0;
}
