#include<iostream>
 using namespace std;
 int main()
 {
    string a;
    getline(cin,a);
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=' ')printf("%c",a[i]);
        else printf("\n");
    }
    return 0;
 }