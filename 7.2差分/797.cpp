#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N];
int n, m;
int main()
{
    cin >> n >> m; // n表示元素个数，m表示循环次数
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        for (int i = l; i <= r; i++)
        {
            p[i] += c;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << " ";
    }
    return 0;
}