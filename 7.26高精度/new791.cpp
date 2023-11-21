#include<iostream>
#include<vector>
using namespace std;
vector<int> add(vector<int> &A,vector<int> &B)
{
    int t=0;
    vector<int> C;
    for(int i=0;i<A.size()||i<B.size();i++)
    {
        if(i<A.size())t+=A[i];
        if(i<B.size())t+=B[i];//此时t是两位之和
        C.push_back(t%10);
        t /= 10;//这里t表示进位 
    }
    //循环结束也就表明两个数都已经轮完
    if(t)C.push_back(t);
    return C;
}
int main()
{
    string a,b;
    cin>>a>>b;//将两个大整数以字符串的形式存储
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
    auto C=add(A,B);
    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
}