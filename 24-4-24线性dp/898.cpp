#include<iostream>
#include<algorithm>
using namespace std;
const int N=510,INF=0x3f3f3f3f;
int n;
int a[N][N];
int f[N][N];//记录每个位置对应的：从起点到该位置的路径长度最大值
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];//读入三角形
        }
    }
    //初始化每个位置路径最大值
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i+1;j++)
        {
            f[i][j]=-INF;
        }
    }
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j]=a[i][j]+max(f[i-1][j-1],f[i-1][j]);//注意左上角和右上角的下标表示
        }
    }
    int res=-INF;
    for(int i=1;i<=n;i++)//枚举最后一行找到最大路径
    {
        res=max(res,f[n][i]);
    }
    cout<<res;
    return 0;
}