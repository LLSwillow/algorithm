#include<iostream>
using namespace std;

const int N=1e5+10;
int m,x,k,idx;
int l[N],r[N],e[N];//数组 l 和 r 表示的是地址索引而不是具体的数值
void init()
{
    l[1]=0;//第0位为 起始位置
    r[0]=1;//第1位为 末位
    //仅表示边界，并没有具体的数值
    idx=2;
}
//在第k位的右侧插入一个值
void Insert(int k,int x)
{
    e[idx]=x;
    r[idx]=r[k];
    l[idx]=k;

    l[r[k]]=idx;
    r[k]=idx;

    idx++;
}

void remove(int k)
{
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}
int main()
{
    init();
    cin>>m;
    string order;
    while(m--)
    {
        cin>>order;
        if(order=="L")//从最左侧插入也就是在第0位的右边插入
        {
            cin>>x;
            Insert(0,x);
        }
        else if(order=="R")//从最右侧插入即在第1位的左边插入
        {
            cin>>x;
            Insert(l[1],x);
        }
        else if(order=="D")
        {
            cin>>k;
            remove(k+1);//第k个插入的数下标为k+1
        }
        else if(order=="IL")
        {
            cin>>k;
            cin>>x;
            Insert(l[k+1],x);
        }
        else if(order=="IR")
        {
            cin>>k;
            cin>>x;
            Insert(k+1,x);
        }
    }

    for(int i=r[0];i!=1;i=r[i])
    {
        cout<<e[i]<<" ";
    }
}