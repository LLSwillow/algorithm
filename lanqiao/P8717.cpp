#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
double n;
int a[N];
int main()
{
	cin>>n;
	double sum=0;
	int Max=0,Min=0x3f3f3f3f;
	double Ave;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		Max=max(Max,a[i]);
		Min=min(Min,a[i]);
	}
	Ave=sum/n;
	printf("%d\n",Max);
	printf("%d\n",Min);
	printf("%.2f\n",Ave);
	return 0;
} 
