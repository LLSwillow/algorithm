#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N], q[N], n, k;
int main()
{
    cin >> n >> k;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int m = 1; m <= n; m++)
    {
        for (int j = m; j <= n; j++)
        {
            q[j] = q[j - 1] + p[j];
            if (q[j] % k == 0)
                count++;
        }
        q[m] = 0;
    }
    cout << count;
    return 0;
}