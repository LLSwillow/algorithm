#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, l, r;

typedef pair<int, int> PII;
vector<PII> segments; // 存储提到的线段

void merge(vector<PII> &segments) // 注意引用操作符
{
    vector<PII> res;

    // 将所有线段按左端点排序
    // pair类型的数据进行排序，优先以左端点排序 当first相同时才看second
    sort(segments.begin(), segments.end());

    // 定义初始区间长度
    int start = -2e9, end = -2e9;

    // 扫描涉及到的线段
    for (auto segment : segments)
    {
        if (end < segment.first) // 当前维护的区间完全 在此时枚举的区间 左边，没有交集，那么该段区间是一个答案
        {
            if (start != -2e9)
                res.push_back({start, end});
            // 更新 下一段将要维护的区间
            start = segment.first;
            end = segment.second;
        }
        else
        {                                   // 此时枚举的区间与所当前维护的区间有交集
            end = max(end, segment.second); // 更新右端点
        }
    }
    // 有可能遍历完之后最后一步执行的仍为else，此时我们要把最后一段符合条件的区间加入到我们的答案中
    if (start != -2e9)
        res.push_back({start, end});

    segments = res;
}
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> l >> r;
        segments.push_back({l, r});
    }
    // 区间和并
    merge(segments);
    // 输出合并之后区间个数
    cout << segments.size() << endl;
    return 0;
}