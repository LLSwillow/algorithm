#include<iostream>
using namespace std;
const int N=1e5+10;
int stk[N],tx,m;
int main()
{
    cin>>m;
    string order;
    while(m--)
    {
        cin>>order;
        if(order=="push")
        {
            int x;
            cin>>x;
            stk[++tx]=x;
        }
        else if(order=="pop")
        {
            if(tx==0)printf("error\n");
            tx--;
        }
        else if(order=="empty")
        {
            if(tx==0)printf("YES\n");
            else printf("NO\n");
        }
        else if(order=="query")
        {
            if(tx==0)printf("error\n");
            printf("%d\n",stk[tx]);
        }
    }
    return 0;
}