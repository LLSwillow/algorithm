#include <iostream>
#include <algorithm>
const int N = 1e5 + 10;
int n, size;
int he[N], ph[N], hp[N];
// size 记录元素个数
// ph数组：存储第k个插入的数 在堆数组中的下标  hp数组：存储 堆里面对应下标的点是 第几个插入的点
using namespace std;

void heap_swap(int a, int b) // a b表示下标 注意传入变量的形式
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(he[a], he[b]);
}
void down(int x)
{
    int t = x; // t表示三个数中的最小值
    if (x * 2 <= size && he[x * 2] < he[t])
        t = x * 2;
    if (x * 2 + 1 <= size && he[x * 2 + 1] < he[t])
        t = x * 2 + 1;
    if (x != t)
    {
        heap_swap(x, t);
        down(t);
    }
}
void up(int x)
{
    while (x / 2 && he[x / 2] > he[x])
    {
        heap_swap(x / 2, x);
        x /= 2;
    }
}
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        char op[2] = {0};
        scanf("%s", op);
        int k, x;
        int i = 0; // i被用作ph数组的索引
        if (op[0] == 'I')
        {
            scanf("%d", &x);
            size++;
            i++;
            ph[i] = size;
            hp[size] = i;
            he[size] = x;
            up(size);
        }
        else if (op[0] == 'P')
        {
            printf("%d\n", he[1]);
        }
        else if (op[0] == 'D' && op[1] == 'M')
        {
            heap_swap(1, size);
            size--;
            down(1);
        }
        else if (op[0] == 'D' && op[1] != 'M')
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, size);
            size--;
            down(k);
            up(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            heap_swap(k, size);
            he[k] = x;
            down(k);
            up(k);
        }
    }
    return 0;
}