#include<iostream>
using namespace std;
int main()
{
    int a,k;//k表示第几位，位数从0开始计算
    cin>>a>>k;
    int ans=(a>>k)&1;
    cout<<ans<<endl;
    return 0;
}