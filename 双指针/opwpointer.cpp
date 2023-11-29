//双指针
#include<iostream>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    for(int i=0;i<a.size();i++)
    {
        int j=i;
        while(j<a.size() && a[j]!=' ')j++;

        for(int k=i;k<j;k++)cout<<a[k];
        cout<<endl;

        i=j;
    }
    return 0;
}