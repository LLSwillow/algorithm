#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3e5 + 10;
int a[N], s[N];
int n, m;

typedef pair<int, int> PII; // 创建一个新的数据类型
vector<int> alls;           // 记录用到的坐标(所以要进行去重和排序)
vector<PII> add, query;     // 分别处理数据的 更改 和 求和

// 二分查找x所在的位置(下标)
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) // 找第一个>=x的数的位置
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        // 把坐标x和后来要添加的c作为一个键值对存储(捆绑在一起)，此时并没有进行操作，后面for循环才执行了操作
        alls.push_back(x); // 把坐标存进alls数组
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r}); // 把将要计算的区间端点存放在query里，后面for循环时实现其功能
        // 将用到的坐标存入alls
        alls.push_back(l);
        alls.push_back(r);
    }
    // alls去重，去掉重复出现的坐标，并排好序存入alls数组，这样alls数组的元素就是一个 使用到的坐标的连续区间了
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto item : add) // 实现add的作用
    {
        int x = find(item.first); // 找到这个数的下标
        a[x] += item.second;      // 改值
    }

    for (int i = 1; i <= alls.size(); i++) // 处理前缀和
    {
        s[i] = s[i - 1] + a[i];
    }
    for (auto item : query) // 处理询问
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}