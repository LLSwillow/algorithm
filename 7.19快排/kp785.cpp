#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], n;
void quicksort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int x = a[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] < x);
        do
        {
            j--;
        } while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    quicksort(a, l, j);
    quicksort(a, j + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    quicksort(a, l, r);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}