// 归并排序： 取中间值作为分界点，将分界点两边的数先排好序，之后将排好序的两边的数逐个进行大小比较，归并为一个序列
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N], tmp[N]; // 需要额外的辅助数组存放归并后的数
void mergesort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;

    mergesort(q, l, mid);
    mergesort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    // tmp->p
    for (i = l, j = 0; i <= r; i++, j++)
    {
        q[i] = tmp[j];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    mergesort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}