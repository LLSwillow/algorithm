#include<iostream>
using namespace std;
const int N=1e5+10,M=1e6+10;
int n,m;
char p[N],s[M];
int ne[N];//ne[1]=0
int main()
{
    cin>>n>>p+1;
    //>>m>>s+1;
    //计算ne数组
    for(int i=2,j=0;i<=n;i++)//这里i也可以从1开始，因为i=1的时候主席那个循环之后，ne[1]也会被赋值为0 所以没影响
    {
        //当j!=0并且下一个元素不匹配的情况下
        while(j && p[i]!=p[j+1])j=ne[j];//就取之前更小的长度
        //如果匹配成功，就继续寻找可能的更长的相等长度
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }
    
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ne[i]);
    }
    /*
    for(int i=1,j=0;i<=m;i++)
    {
        while(j && s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        if(j==n)
        {
            printf("%d ",i-n);//本来是i-n+1，但这里题目要求我们下标从0开始
            j=ne[j];
        }
    }*/
    return 0;
}