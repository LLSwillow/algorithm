#include<iostream>
#include<algorithm>
#include<string>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N],b[N],p[N],q[N];
int n,m;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		p[i]=p[i-1]+a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		//cout<<b[i]<<" ";
		q[i]=q[i-1]+b[i];
	}
	
	cin>>m;
	while(m--)
	{
		int op;
		cin>>op;
		int l,r;
		cin>>l>>r;
		if(op==1)
		{
			cout<<p[r]-p[l-1]<<endl;
		}
		else{
			cout<<q[r]-q[l-1]<<endl;
		}
	}
	return 0;
}
