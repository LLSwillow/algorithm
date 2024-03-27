#include<iostream>
#define int long long
using namespace std;
const int N=1e5+10;
int n,k;
int s[N];//用来存储同一个余数的个数
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int sum=0;
	s[0]=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		sum+=x%k;
		s[sum%k]++;
		sum%=k;
	}
	int cnt=0;
	for(int i=0;i<k;i++)//遍历所有可能的相同余数
	{
		cnt+=(s[i]*(s[i]-1))/2;
	}
	cout<<cnt;
	return 0;
 } 
