#include<iostream>
#include<cstring>
using namespace std;
const int N=1e3+10;
int p[N],s[N][N],n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    char op[2];
    while(m--)
    {
        scanf("%s",op);
        int a=0,b=0;
        if(strcmp(op,"M")==0)
        {
            cin>>a>>b;
            if(s[a][b]==1)break;
            else s[a][b]=1;

            //printf("%d",s[a][b]);
        }
        else if(strcmp(op,"Q")==0){
            cin>>a>>b;
            bool ans=s[a][b];
            if(ans==1)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}