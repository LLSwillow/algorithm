#include<iostream>
#include<algorithm>
using namespace std;
int get(int a,int b)
{
	int l=1;
	int r=1e9+1;//避免参数b=0时，结果的冲突 
	
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a/mid<=b)r=mid;
		else l=mid+1;
	}
	return l;
}
int get2(int a,int b)
{
	int l=1;
	int r=1e9+1;//避免参数b=0时，结果的冲突 
	
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(a/mid>b-1)l=mid;
		else r=mid-1;
	}
	return l;
 } 
int main()
{
	int n;
	scanf("%d",&n);
	int Min=1,Max=1e9;
	while(n--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		Min=max(Min,get(a,b));//求这 n 组数据满足的最小值的交集 
		Max=min(Max,get2(a,b));//最大值 
	}
	printf("%d %d",Min,Max);
	return 0;
 } 
