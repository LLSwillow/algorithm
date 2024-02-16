#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510, M = 1e5 + 10;
int n1, n2, m;
int h[N], e[M], ne[M], idx; // 由于我们只考虑左侧的点，因此采用邻接表存储是合理的
int match[N];               // 记录右侧顶点匹配的左侧顶点编号：下标表示右侧顶点 match数组表示的是左侧顶点
bool st[N];                 // 标记右侧顶点是否已经被访问
void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}
bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) // 先检查右侧顶点 j 在这一轮中是否被访问过
        {
            st[j] = 1;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v); // 因为只需要遍历左侧顶点
    }
    int res = 0;
    for (int i = 1; i <= n1; i++) // 遍历左侧节点
    {
        memset(st, 0, sizeof st); // 以便重新标记每个右侧顶点的访问状态，不会受到之前搜索状态的影响
        if (find(i))
            res++;
    }
    cout << res;
    return 0;
}