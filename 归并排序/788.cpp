#include<iostream>
using namespace std;
const int N=100010;
int q[N],res[N];
int n,count;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
        res[i]=q[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(q[i]<res[j])count++;
        }
    }
    cout<<count;
    return 0;
}
