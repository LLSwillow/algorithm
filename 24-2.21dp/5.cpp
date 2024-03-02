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
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            count++;
            v[count] = a * k;
            w[count] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            count++;
            v[count] = a * s;
            w[count] = b * s;
        }
    }
    n = count;
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