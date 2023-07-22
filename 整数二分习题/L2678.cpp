#include <iostream>
using namespace std;
const int N = 50005;
int length, n, m, a[N];
bool check(int x)
{
    int t = 0, count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - t < x)
            count++;
        else
            t = a[i];
    }
    return count <= m;
}
int find(int l, int r)
{
    if (l == r)
        return r;
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
    cin >> length >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = find(0, length);
    cout << ans;
    return 0;
}