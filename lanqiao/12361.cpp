#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N],c[N];
int a1[N],c1[N];
int sa[N],sc[N];
int as[N],cs[N];
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
	
	for(int i=0;i<n;i++)a1[a[i]]++;
	for(int i=0;i<=N;i++)sa[i]=sa[i-1]+a1[i];
	for(int i=0;i<n;i++)as[i]=sa[b[i]-1];
	
	for(int i=0;i<n;i++)c1[c[i]]++;
	for(int i=0;i<=N;i++)sc[i]=sc[i-1]+c1[i];
	for(int i=0;i<n;i++)cs[i]=sc[N]-sc[b[i]];
	
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=as[i]*cs[i];
	}
	cout<<cnt;
	return 0;
 }
