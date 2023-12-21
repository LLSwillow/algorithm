#include<iostream>
using namespace std;
const int N=1e5+10;
int que[N],hh,tt,m;
int main()
{
    hh=0,tt=-1;
    cin>>m;
    string order;
    while(m--)
    {
        cin>>order;
        if(order=="push"){
            int x;
            cin>>x;
            que[++tt]=x;
        }
        else if(order=="pop")
        {
            hh++;
        }
        else if(order=="empty")
        {
            if(hh<=tt)printf("NO\n");
            else printf("YES\n");
        }
        else if(order=="query")
        {
            if(hh>tt)printf("error\n");
            else printf("%d\n",que[hh]);
        }
    }
    return 0;
}