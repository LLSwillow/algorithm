#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10, M = 2010;
int n, m;
int v[N], w[N];
int dp[M];
int main()
{
    cin >> n >> m;
    int count = 0;//记录当前物品种类的数量
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;//因为可能要进行二进制化，所以不能直接复制到v w数组中
        int k = 1;//表示每种物品在二进制拆分时的数量，初始值为1，表示从拆分后的最小数量开始，也就是2的0次方
        while (k <= s)
        {
            count++;
            v[count] = a * k;
            w[count] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0)//处理剩余的物品数量，如果剩余数量不为0，则将剩余数量作为一个单独的物品添加到数组中。
        {
            count++;
            v[count] = a * s;
            w[count] = b * s;
        }
    }
    n = count;
    //直接写01背包的一维优化
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m];
    return 0;
}