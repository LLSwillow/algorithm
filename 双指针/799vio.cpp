#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N],n,res,len;

bool check(int l,int r)
{
    if(l>=r)return 0;
    for(int i=l;i<r;i++)
    {
        if(a[i]==a[r])return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)//j指针最左能在哪
        {
            if(check(j,i))
            {
                res=max(res,i-j+1);
            }
        }
    }
    cout<<res;
    return 0;
}