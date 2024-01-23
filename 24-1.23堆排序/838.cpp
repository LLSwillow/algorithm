#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,m;
int he[N],size;

//调整以 x 为根的子树，以满足小根堆的性质
void down(int x)
{
    int t=x;//t表示三个数中的最小值
    if(x*2<=size && he[x*2]<he[t])t=x*2;
    if(x*2+1<=size && he[x*2+1]<he[t])t=x*2+1;
    if(x!=t)
    {
        swap(he[x],he[t]);
        down(t);
    }
}

void up(int x)
{
    while(x/2 && he[x/2]>he[x])
    {
        swap(he[x/2],he[x]);
        x /= 2;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&he[i]);
    }

    size=n;//size标记数组最后一个元素

    for(int i=n/2;i;i--)down(i);
    
    while(m--)
    {
        printf("%d ",he[1]);
        he[1]=he[size];
        size--;
        down(1);
    }
    return 0;
}