#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N],c[N];
int n;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n;i++)cin>>c[i];
	
	sort(a, a+n);
	sort(b, b+n);
	sort(c, c+n);
	
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int l=lower_bound(a,a+n,b[i])-a,r=n-(upper_bound(c,c+n,b[i])-c);
		cnt+=l*r;
	}
	cout<<cnt;
	return 0;
 }
