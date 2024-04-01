#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N],c[N],b1[N],c1[N];
int n;
int find(int q[],int x)
{
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(q[mid]>x)r=mid-1;
		else l=mid;
	}
	if(q[l]>x)return l;
	else if(q[l]==x)return l+1;
	else return -1;
}
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
		
		for(int j=find(b,a[i]);j<n;j++)
		{
			/*
			for(int k=find(c,b[j]);k<n && k!=-1;k++)
			{
				cnt++;
			}*/
			int k=find(c,b[j]);
			cnt+=n-k;
		}
	}
	cout<<cnt;
	return 0;
 } 
