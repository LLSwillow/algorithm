#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string a;
	cin>>a;
	int b;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>48 && a[i]<=57)
		{
			b=a[i]-'0';
			b-=1;
			while(b--)
			{
				cout<<a[i-1];
			}
		}
		else cout<<a[i];
	}
	return 0;
}
