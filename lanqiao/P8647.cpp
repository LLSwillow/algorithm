#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,k;
int h[N],w[N];
bool check(int x)
{
	int count=0;
	int a,b;
	for(int i=0;i<n;i++)
	{
		a=h[i]/x,b=w[i]/x;
		count+=a*b;
	}
	return count>=k;
}
int besearch(int l,int r)
{
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else r=mid-1;
	}
	return l;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>h[i]>>w[i];
	}
	int ans=besearch(1,1e5);
	cout<<ans;
	return 0;
 } 
