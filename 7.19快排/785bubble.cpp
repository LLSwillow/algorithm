#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], n;
void bubble(int a[], int n)
{
    int flag = 1;
    for (int i = 0; i < n; i++) // 有n个数需要排序
    {
        for (int j = 0; j < n - i - 1; j++) // 针对每一个数，都要进行n-i-1次比较
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                flag = 0;
            }
        }
        if (flag == 1)
            break; // 倘若一个循环下来都没有交换数据说明本来这个序列就是有序的
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bubble(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}