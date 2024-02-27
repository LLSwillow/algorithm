#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int n, m;       // n表示物品数量 m表示背包容量
int v[N], w[N]; // v数组存储每件物品的体积，w数组存储每件物品的权值
int dp[N][N];   // dp[i][j]二维数组的每个元素表示的是：只从前i个物品中选择，且容量要小于j的情况下的最大价值
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i]; // 读取每件物品
    // 当i为0，也就是有0个可选物品，那么其对应的所有j容量值的情况下价值都为0，刚好初始化的时候就是全部初始化为0，因此我们i从1开始
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // 状态计算
            // 不包含第i个物品
            dp[i][j] = dp[i - 1][j];
            // 包含第i个物品 只有当第i个物品的体积小于当前最大容量的时候我们才考虑这种情况，否则没有意义
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][m];
    return 0;
}