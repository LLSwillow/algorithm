#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int n, m;
int v[N][N], w[N][N], s[N];
int dp[N];
int main()
{
    cin >> n >> m; // n表示组数

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i]; // 表示这一组的物品数量
        for (int j = 0; j < s[i]; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k < s[i]; k++) // 涉及到不选这组物品/选这组物品的哪一个
            {
                if (v[i][k] <= j)
                {
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}