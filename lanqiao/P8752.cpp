#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	int i=5;
	int count=0;
	while(i--)
	{
		cin>>a;
		if(a[0]==a[2] && a[3]-a[1]==1)
		{
			count++;
		}
	}
	cout<<count;
	return 0;
 } 
