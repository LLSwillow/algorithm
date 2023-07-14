#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n, q;
int find2(int begin, int right, int a[], int k) // 找end
{
    int j = 0; // 表示目标元素出现的次数
    while (begin <= right)
    {
        if (a[++begin] == k) // begin前置++是因为我们想得到的是begin之后有多少个目标元素，不包含本来就已经有的这一个
        {
            j++;
        }
    }
    return j;
}
void find(int a[], int k, int n) // 查找数组中遇到的第一个目标元素
{
    int left = 0;
    int right = n - 1;
    int begin = -1, end = -1; // 令初始值为-1 -1 当数组中没有目标元素时直接输出
    while (left <= right)
    {
        if (a[left] == k) // 只要找到了数组中第一个目标元素，就得到了begin
        {
            begin = left;
            end = begin + find2(begin, right, a, k); // 得到begin之后找end
            break;                                   // 那么这个循环得功能就已经实现了，break跳出循环即可，避免给begin多次赋值而导致错误
        }
        left++; // 必须在这里++而不能在前面if语句里，是因为如果在if语句里++，会导致begin赋值错误
    }
    cout << begin << " " << end << endl;
}
int main()
{
    cin >> n >> q;
    int i = 0; // 表示数组下标从零开始
    int j = n;
    while (j--) // 用j来代替n做遍历，避免下面find函数的参数n值得改变出现错误
    {
        cin >> a[i++];
    }
    int k = 0; // 目标元素
    while (q--)
    {
        cin >> k;
        find(a, k, n);
    }
    return 0;
}