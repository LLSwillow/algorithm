#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N];
int n,m,q;
int find(int q)
{
    int l=1,r=n;
    //int l=a[1],r=a[n];
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(a[mid]>=q)r=mid;
        else l=mid+1;
    }
    if(a[l]==q)return l;
    else return -1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        cin>>q;
        int ans=find(q);
        cout<<ans<<" ";
    }
    return 0;
}