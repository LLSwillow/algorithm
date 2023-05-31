/*快速排序：随便找一个数作为分界点，让两个指针（数组下标）从数组左右边界开始 向中间行走，
当检索到数组下标所对应的元素大于或小于分界点的时候，停下，当两个指针都停下且所在位置满足i<j时交换两个元素*/
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int q[N];

int n;

void quick_sort(int q[], int l, int r) // 传入需要进行排序的数组，左边界，右边界
{
    if (l >= r)
        return;
    int x = q[l], i = l - 1, j = r + 1; // i j 表示边界 定义分界点，左右预备边界
    while (i < j)
    {
        do
        {
            i++;
        } while (q[i] < x);
        do
        {
            j--;
        } while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j); // 左右匹配 q[l] j q[j] i-1
    quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n); // 几个数字进行排序
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]); // 录入需要排序的数据

    quick_sort(q, 0, n - 1); // 传过去整个数组，和数组首尾下标

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]); // 输出排好序的数

    return 0;
}