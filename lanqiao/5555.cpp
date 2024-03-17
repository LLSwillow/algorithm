#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
int n;
int a[N];
int main()
{
	cin>>n;
	int x=0,y=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%2==0)x++;
		else y++;
	}
	if(x==y)cout<<"Yes";
	else cout<<"No";
	return 0;
 } 
