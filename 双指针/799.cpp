#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N],n,len;
bool compare(int a[],int x,int i)
{
    
}

int main()
{
    int ans=0;
    len=1;//初始状态为 1 是为了计算上其自身
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(compare(a,a[i],i) && i!=1)len++;//避免第一个元素重复计算
        else{
            ans=max(len,ans);
            len=1;}
    }
    ans=max(len,ans);
    cout<<ans;
    return 0;
}