#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
vector<PII> p;
int main()
{
	int n,a,b;
	scanf("%d",&n);
	int Max=0x3f3f3f3f; 
	while(n--)
	{
		scanf("%d %d",&a,&b);
		p.push_back({a,b});
		Max=min(Max,a/b);
	}
	int k=Max;
	int flag=0;
	int Min=Max;
	while(--k)
	{
		for(int i=0;i<p.size();i++)
		{
			if(p[i].first/k!=p[i].second)
			{
				flag=1;
				break;
			}
		}
		Min=min(Min,k);
		if(flag){
			Min=Min+1;
			break;
		}
	}
	cout<<Min<<" "<<Max;
	return 0;
}
