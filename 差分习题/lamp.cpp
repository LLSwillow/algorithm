#include <iostream>
using namespace std;
const int N = 5e5 + 10;
long long p[N],q[N];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        p[i] = q[i] - q[i - 1];
    }
    while (m--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        p[l] += x;
        p[r + 1] -= x;
    }
    for (int i = 1; i <= n; i++)
    {
        q[i] = q[i - 1] + p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << max(q[i], 0) << " ";
        if (q[i] < 0)
            q[i] = 0;
        cout << q[i] << " ";
    }
    return 0;
}
