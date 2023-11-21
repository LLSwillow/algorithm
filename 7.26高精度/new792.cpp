#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int> &A,vector<int> &B)
{
    if(A.size()!=B.size())return A.size()>B.size();
    else{
        for(int i=A.size()-1;i>=0;i--)
        {
            if(A[i]!=B[i])return A[i]>B[i];
        }
        return 1;
    }
}
vector<int> subtraction(vector<int> &A,vector<int> &B)
{
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++)
    {
        t =A[i]-t;
        if(i<B.size())t-=B[i];//这里t表示减法之后的结果 
        C.push_back((t+10)%10);
        if(t<0)t=1;//这里t表借位
        else t=0;
    }
    while(C.size()>1 && C.back()==0)C.pop_back();//193-99=094 要消去高位的0
    return C;
}
int main()
{
    string a,b;
    cin>>a>>b;
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
    if(cmp(A,B))
    {
        auto C=subtraction(A,B);
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }
    else{
        auto C=subtraction(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }
    return 0;
}