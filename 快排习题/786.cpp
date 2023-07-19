#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n, k;
int quicksort(int a[], int l, int r, int k)
{
    if (l >= r)
        return a[l];
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
    /*
    quicksort(a,l,j);
    quicksort(a,j+1,r);*/
    int s = j - l + 1;
    if (k <= s)
        return quicksort(a, l, j, k);
    return quicksort(a, j + 1, r, k - s);
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    quicksort(a, l, r, k);
    cout << a[k - 1];
    return 0;
}