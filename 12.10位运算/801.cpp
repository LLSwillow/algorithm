#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N],n;
string Binary(int a)
{
    string b;
    int k=0;
    while(a)
    {
        b+='0'+a%2;
        a /= 2;
    }
    reverse(b.begin(),b.end());
    return b;
}
int main()
{
    string b;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b=Binary(a[i]);
        for(int j=0;j<b.size();j++)
        {
            if(b[j]=='1')sum++;
        }
        a[i]=sum;
        sum=0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}