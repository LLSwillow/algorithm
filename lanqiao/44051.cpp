#include<iostream>
#include<algorithm>
using namespace std;
const int N=510;
int n,m,k;
int q[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>q[i][j];
			q[i][j]+=q[i-1][j];//�����ÿһ�е�ǰ׺�;��� 
		}
	}
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)//ö�����±߽� 
		{
			for(int l=1,r=1,sum=0;r<=m;r++)//���ұ߽�Ļ������� 
			{
				//��������Ŀ��˵��<=kʱ�����Ǿ��ؿ��ұ߽� 
				sum+=q[j][r]-q[i-1][r];//�����r�߽�˵���Ӿ���ĺ� 
				//�����ϵ�ʱ�����Ǿ�Ҫ����߽������ƶ� 
				while(sum>k)
				{
					sum-=q[j][l]-q[i-1][l];//��ȥ�Ƴ�ȥ����˵㴦�ĺ�
					l++;
				}
				//ÿ�δ��ڵ��ƶ����õ������������Ӿ���ĸ��� =�ұ߽� r ��ȥ��߽� l �ټ��� 1
				cnt+=r-l+1;
			}
		}
	 } 
	cout<<cnt;
	return 0;
}
