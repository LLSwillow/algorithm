#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int a[N],q[N];
int n;
int main()
{
	cin>>n;
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q[i]=q[i-1]+a[i];
	}
	
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			s+=a[i]*a[j];
		}
	}*/
	
	for(int i=1;i<=n;i++)
	{
		s+=a[i]*(q[n]-q[i]);
	}
	cout<<s;
	return 0;
}
