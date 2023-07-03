#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N],q[N];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>q[i];//输入前缀和数组
        p[i]=q[i]-q[i-1];//得到原数组
    }
    while(m--)
    {
        int l,r,c;
        cin>>l>>r>>c;
        p[l] += c;
        p[r+1] -= c;
    }
    for(int i=1;i<=n;i++)
    {
        q[i]=q[i-1]+p[i];
        cout<<q[i]<<" ";
    }
    cout<<endl;
    return 0;
}