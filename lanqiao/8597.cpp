#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        if(b[i]=='*')b[i]=1;
        if(b[i]=='o')b[i]=2;

        if(a[i]=='*')a[i]=1;
        if(a[i]=='o')a[i]=2;
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        {
            b[i+1]=3-b[i+1];
            b[i]=3-b[i];
            count++;
        }
        else continue;
    }

    cout<<count;
    return 0;
}