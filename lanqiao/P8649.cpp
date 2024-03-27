#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,k;
int a[N],q[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int count=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q[i]=q[i-1]+a[i];
		if(q[i]%k==0)count++;
	}
	for(int i=2;i<n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			q[j]-=a[i-1];
		    if(q[j]%k==0)
		    {
		    	count++;
		    }	
	    }
	}
	if(a[n]%k==0)count++;
	cout<<count;
	return 0;
}
