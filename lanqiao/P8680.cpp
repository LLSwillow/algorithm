#include<iostream>
#include<algorithm>
using namespace std;
int n,sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp=i;
		while(tmp)
		{
			if(tmp%10==2 || tmp%10==0 || tmp%10==1 || tmp%10==9)
			{
				sum+=i;
				break;
			}
			tmp/=10;//数位分解 
		}
	}
	cout<<sum;
	return 0;
}
