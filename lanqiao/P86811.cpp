#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
long long sum;

int main()
{
	cin>>n;
	int x;
	int num=0,d=1;//num表示这一层当前读取的数字个数 ，d表示当前层数 
	long long maxx=-1e18;//maxx表示最大权值和
	int mxid=0;//mxid表示其层数 
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
		num++;
		if(num==pow(2,d-1) || i==n)
		{
			if(sum>maxx){
				maxx=sum;
				mxid=d;
			}
			//当开始进行新的一层运算时
			sum=num=0; 
			d++;
		}
	}
	cout<<mxid;
	return 0;
 } 
