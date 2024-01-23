#include<iostream>
using namespace std;
const int N=1e5;
int n,m;
int p[N];
int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);//路径压缩
    return p[x];//返回根节点 也就是集合编号
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    while(m--)
    {
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(op[0]=='M')p[find(a)]=find(b);//这里是用一个字符型元素比较的因此可以直接==比较
        else {
            if(find(a)==find(b))puts("Yes");
            else puts("No");
        }
    }
}