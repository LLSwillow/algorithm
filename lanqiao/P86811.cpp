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
	int num=0,d=1;//num��ʾ��һ�㵱ǰ��ȡ�����ָ��� ��d��ʾ��ǰ���� 
	long long maxx=-1e18;//maxx��ʾ���Ȩֵ��
	int mxid=0;//mxid��ʾ����� 
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
			//����ʼ�����µ�һ������ʱ
			sum=num=0; 
			d++;
		}
	}
	cout<<mxid;
	return 0;
 } 
