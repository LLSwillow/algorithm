#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N];//数据个数
int main()
{
    int n;
    cin>>n;
    int x=0;
    int ans1,ans2;
    while(cin>>x)
    {
        a[x]++;
    }
    for(int i=0;i<10001;i++)
    {
        if(a[i]==0 && a[i-1]==1 && a[i+1]==1)
        {
            ans1=i;
        }
        if(a[x]>1)ans2=i;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}