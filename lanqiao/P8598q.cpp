#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int q;
int a[N];
int m,n;
int main()
{
    cin>>q;
    int i=0;
    while(cin>>a[i])i++;
    sort(a,a+i);
    for(int j=0;j<i;j++)
    {
        if(a[j]==a[j+1])n=a[j];
        if(a[j+1]-a[j]>1)m=a[j]+1;
    }
    cout<<m<<" "<<n;
    return 0;
}