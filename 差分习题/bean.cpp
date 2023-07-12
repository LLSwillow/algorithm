#include <iostream>
using namespace std;
const int N = 2001;
int p[N][N];
int n, m, k, q;
int main()
{
    cin >> n >> m >> k >> q;
    int x1, y1, x2, y2;
    // 放豆子对差分数组中某些数据的修改
    while (k--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        p[x1][y1] += 1;
        p[x1][y2 + 1] -= 1;
        p[x2 + 1][y1] -= 1;
        p[x2 + 1][y2 + 1] += 1;
    }
    // 实现 对前缀和数组中 某块区域值的修改
    // 接下来的操作是为了得到放完豆子后的棋盘【差分算法中的前缀和数组】
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + p[i][j];
        }
    }
    // 由于所求的就是现在这个棋盘中某块区域的值的和，所以接下来就完全是前缀和算法的实现了
    // 需要有一个思维的转变，这时棋盘表示的数组就应当看作 在前缀和算法中的 原数组了
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + p[i][j];
        }
    }
    // 所求区域的前缀和
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}