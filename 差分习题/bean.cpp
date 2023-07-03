#include<iostream>
using namespace std;
const int N=2001;
int p[N][N];
int n,m,k,q;
int main()
{
    cin>>n>>m>>k>>q;
    int x1,y1,x2,y2;
    //放豆子【由于这道题并没有给出已知数组[看作前缀和的数组] 所以我们只需要开辟一个数组直接表示[用所给数组推出]原数组即可】
    while(k--)
    {
        cin>>x1>>y1>>x2>>y2;
        p[x1][y1] += 1;
        p[x1][y2+1] -= 1;
        p[x2+1][y1] -= 1;
        p[x2+1][y2+1] += 1;
    }
    //放完豆子后的棋盘【前缀和数组】但其实表示含义应该是前缀和算法中的原数组
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] +p[i][j];
        }
    }
    //对原数组求前缀和
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] +p[i][j];
        }
    }
    //所求区域的前缀和
    while(q--)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1]<<endl;
    }
    return 0;
}