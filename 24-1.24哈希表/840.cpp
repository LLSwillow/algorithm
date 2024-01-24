#include<iostream>
#include<cstring>//初始化数组memset的头文件
using namespace std;
const int N=1e5+3;//大于1e5的第一个质数
int ha[N],n;//ha数组存储的是：哈希值为 k 的所有数的 链表的头节点
int ne[N],e[N],idx;//e数组存储数据 ne数组存储下一个节点的地址 idx表示分配地址的下标

void Insert(int x)
{
    int k=(x%N+N)%N;//计算出哈希值
    //头插法
    e[idx]=x;
    ne[idx]=ha[k];
    ha[k]=idx++;
}
bool find(int x)
{
    int k=(x%N+N)%N;
    for(int i=ha[k];i!=-1;i=ne[i])//单链表的遍历
    {
        if(e[i]==x)return 1;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);

    memset(ha,-1,sizeof ha);//初始化数组值为-1

    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);

        if(op[0]=='I')Insert(x);
        else{
            if(find(x))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

/*
#include<iostream>
using namespace std;
int main()
{
    for(int i=100000;;i++)
    {
        int flag=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<i;
            break;
        }
    }
    return 0;
}*/