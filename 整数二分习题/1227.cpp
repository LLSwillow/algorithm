#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int h[N], w[N];
bool check(int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += (h[i] / x) * (w[i] / x);
    }
    return count >= k;
}
int find(int l, int r)
{
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
    }
    int ans = find(1, 1e5);
    cout << ans;
    return 0;
}