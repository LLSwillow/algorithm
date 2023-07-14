#include <iostream>
using namespace std;
const int N = 100000;
int a[N];
int n, q;
int main()
{
    cin >> n >> q;
    // 输入数组
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // 开始执行询问
    while (q--)
    {
        // 输入目标元素
        int k;
        cin >> k;
        // 定义左右边界
        int left = 0, right = n - 1; // 位置从零开始

        // 开始二分边界
        while (left < right) // 注意不可取等
        {
            int mid = left + (right - left) / 2;
            // 根据题目需要，首先要找到数组中 出现第一个目标元素 的位置---查找不小于目标值的第一个位置

            if (a[mid] >= k)
                right = mid;
            else
                left = mid + 1;
        }

        // 循环出口是right=left=mid
        // 通过上述二分:不论数组中k是否存在，都会得到一个mid值
        // 所以我们要先判断该值是否等于k

        if (a[left] != k) // 说明数组中不存在k
            cout << "-1 -1" << endl;
        else // a[mid]=k时，说明起始位置已经找到，接下来要找终止位置
        {
            cout << left << " "; // 记得输出起始位置 注意空格

            left = 0;
            right = n - 1;
            // 查找终止位置 ---查找不大于目标值的最后一个位置
            while (left < right)
            {
                int mid = left + right + 1 >> 1; // 为了避免死循环需要+1再除二
                if (a[mid] <= k)
                    left = mid;
                else
                    right = mid - 1;
            }
            cout << left << endl;
        }
    }
    return 0;
}