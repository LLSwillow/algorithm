#include <iostream>
using namespace std;
const int N = 1001;
int p[N][N], q[N][N];
int n, m, k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> q[i][j];
            // 还原原数组
            p[i][j] = q[i][j] - q[i - 1][j] - q[i][j - 1] + q[i - 1][j - 1];
        }
    }
    while (k--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        // 进行修改值的操作
        p[x1][y1] += c;
        p[x2 + 1][y1] -= c;
        p[x1][y2 + 1] -= c;
        p[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 前缀和
            q[i][j] = q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1] + p[i][j];
            cout << q[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}