//90·Ö 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N];
long long sum[N];
int n;
int main()
{
	cin>>n;
	int j=1;
	int cnt=1;
	int x=1;
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[j]+=a[i]; 
		if(i==x)
		{
			if(sum[j]>sum[j-1])
			{
				ans=j;
			}
			if(sum[j]==sum[j-1])
			{
				ans=min(ans,j);
			}
			j++;
			cnt=2*cnt;
			x+=cnt;
		}
	}
	if(sum[j]>sum[ans])ans=j;
	else if(sum[j]==sum[ans])ans=ans;
	cout<<ans;
	return 0;
}
