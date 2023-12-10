#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int ans=a&(-a);
    cout<<ans<<endl;
    return 0;
}