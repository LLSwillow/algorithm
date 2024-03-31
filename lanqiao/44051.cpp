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
			q[i][j]+=q[i-1][j];//计算出每一列的前缀和矩阵 
		}
	}
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)//枚举上下边界 
		{
			for(int l=1,r=1,sum=0;r<=m;r++)//左右边界的滑动窗口 
			{
				//当符合题目所说的<=k时，我们就拓宽右边界 
				sum+=q[j][r]-q[i-1][r];//添加上r边界端点的子矩阵的和 
				//不符合的时候，我们就要把左边界向右移动 
				while(sum>k)
				{
					sum-=q[j][l]-q[i-1][l];//减去移出去的左端点处的和
					l++;
				}
				//每次窗口的移动所得到的满足条件子矩阵的个数 =右边界 r 减去左边界 l 再加上 1
				cnt+=r-l+1;
			}
		}
	 } 
	cout<<cnt;
	return 0;
}
