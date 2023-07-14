#include <iostream>
using namespace std;
const int N = 100000;
int a[N];
int n, q;
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int k;
        cin >> k;
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (a[mid] >= k)
                right = mid;
            else
                left = mid + 1;
        }
        if (a[left] != k)
            cout << "-1 -1" << endl;
        else
        {
            cout << left << " ";

            left = 0;
            right = n - 1;
            while (left < right)
            {
                int mid = left + right + 1 >> 1;
                if (a[mid] <= k)
                    left = mid;
                else
                    right = mid - 1;
            }
            cout << left << endl;
        }
    }
    return 0;
}