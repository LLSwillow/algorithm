#include<iostream>
#include<algorithm>
using namespace std;

int n;
int main()
{
	cin>>n;
	double m=(double)n/2;
	int a;
	int count=0;
	for(int i=1;i<n;i++)
	{
		a=(i*i)%n;
		if(a<m)count++;
	}
	cout<<count;
	return 0;
}
