#include <iostream>
using namespace std;
const int N = 12;
int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s)
{
    if (y == n) // 该行已经遍历完了，因此列标要重新从0开始，行数+1
    {
        y = 0;
        x++;
    }
    if (x == n) // 遍历到了最后一行
    {
        if (s == n) // 如果皇后数量也足够的话，说明找到了一个答案
        {
            for (int i = 0; i < n; i++)
            {
                puts(g[i]);
            }
            puts("");
        }
        return;
    }

    // 不放皇后，就直接到下一个格子也就是下一列y+1
    dfs(x, y + 1, s);

    // 如果满足这些条件会放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[y - x + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[y - x + n] = 1;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[y - x + n] = 0;
        g[x][y] = '.';
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    dfs(0, 0, 0); // 从第0行第0列即左上角开始搜，此时已经放过的皇后数量为0

    return 0;
}