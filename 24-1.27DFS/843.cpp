#include<iostream>
using namespace std;
const int N=12;
int n;
int path[N];
bool st[N];

void dfs(int x)
{
    if(x==n)
    {
        for(int i=0;i<n-1;i++)//只判断了相邻两个皇后是否处于同一斜线
        {//由于数组会索引到i+1 因此第二个表达式应该是i<n-1
            if(path[i]-path[i+1]==1 || path[i]-path[i+1]==-1)return;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(path[i]==j)
                {
                    printf("Q");
                }
                else{
                    printf(".");
                }
            }
            puts("");
        }
        puts("");
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(!st[i])
        {
            st[i]=1;
            path[x]=i;
            dfs(x+1);
            st[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);

    dfs(0);

    return 0;
}