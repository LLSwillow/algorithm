#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    string p,s;
    cin>>n;
    cin>>p;//模板串  子串
    cin>>m;
    cin>>s;//模式串  主串
    int k=0;
    int start=-1;
    vector<int> ans;
    int v=0;
    for(int i=0;i<m;i++)
    {
        if(s[i]==p[0]){
            start=i;
            k=start;
            for(int j=0;j<n;j++,k++)
            {
                if(s[k]!=p[j])
                {
                    k=0;
                    start=-1;
                    break;
                }
            }
            if(start!=-1)ans.push_back(start);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}