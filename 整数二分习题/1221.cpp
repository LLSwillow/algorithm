#include <iostream>
using namespace std;
int n;
int a[4];
void square(int l, int r)
{
    int i = 0;
    if (l >= r)
        return;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (mid <= n / mid)
            l = mid;
        else
            r = mid - 1;
    }
    a[i++] = l;
    if (l * l == n)
        return;
    int k = n;
    while (l * l < k)
    {
        r = k - l * l, l = 0;
        int j = r;
        while (l < r)
        {
            int x = (l + r + 1) / 2;
            if (x <= j / x)
                l = x;
            else
                r = x - 1;
        }
        a[i++] = l;
        if (l * l == j)
            return;
        k = j;
    }
}
int main()
{
    cin >> n;
    square(0, n);
    for (int i = 3; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    return 0;
}