#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], s[N], n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++;          // s数组记录每一个数出现的次数
        while (s[a[i]] > 1) // 读入了i之后，有了重复元素，所以我们j指针往后移一位，
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res;
    return 0;
}