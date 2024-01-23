#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m, p[N], size[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x]; // 不要写else
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        size[i] = 1;
    }
    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s", op);
        if (op[0] == 'C')
        {
            scanf("%d%d", &a, &b); // scanf会自动过滤空格
            if (p[a] == p[b])
                continue;
            size[find(b)] += size[find(a)]; // 这里两个集合并没有合并，还是两棵树
            p[find(a)] = find(b);           // 这里更新了两棵树中所有元素的根节点
        }
        else if (op[1] == '1')
        {
            scanf("%d%d", &a, &b);
            if (p[a] == p[b])
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            scanf("%d", &a);
            printf("%d", size[find(a)]);
        }
    }
    return 0;
}