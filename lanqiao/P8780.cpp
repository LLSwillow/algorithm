#include<iostream>
#include<algorithm>
using namespace std;
long long a,b,n;
int main()
{
	cin>>a>>b>>n;
	long long sum=0;
	long long i,j;
	for(i=1;sum<n;i++)
	{
		j=i%7;
		if(j<=5 && j>0)sum+=a;
		if(j>5 || j==0)sum+=b;
	}
	cout<<i-1;
	return 0;
}
