#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+3,null=0x3f3f3f3f;
int ha[N],n;
int find(int x)
{
    int k=(x%N+N)%N;
    while(ha[k]!=null && ha[k]!=x)//如果当前哈希值的位置有数据并且这个数不是我们正在处理的这个数，就要向后找能放它的位置
    {
        k++;
        if(k==N)k=0;
    }
    return k;
}
int main()
{
    scanf("%d",&n);

    memset(ha,0x3f,sizeof ha);

    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);

        int k=find(x);
        if(op[0]=='I')ha[k]=x;
        else{
            if(ha[k]!=null)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}