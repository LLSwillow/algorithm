#include <iostream>
using namespace std;
int x;
int main()
{
    cin >> x;
    int l = 0, r = x;
    while (l < r) 
    {
        int mid = (l + r + 1) / 2;
        if (mid <= x / mid)
            l = mid; 
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}