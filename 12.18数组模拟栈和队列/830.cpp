#include<iostream>
using namespace std;
const int N=1e5+10;
int stk[N],tt,n;
int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)//因为要找每一个数左边离他最近的小于它的数，所以直接在输入元素的时候就对其进行判断
    {
        int x;
        scanf("%d",&x);
        while(tt && stk[tt]>=x)tt--;//当栈不为空，且栈顶元素大于该数，就将栈顶元素出栈。直到找到第一个<该数的元素
        if(tt)printf("%d ",stk[tt]);//如果在栈不为空时找到了则输出
        else printf("-1 ");//没找到

        stk[++tt]=x;//将这个新的数据入栈
    }
    return 0;
}