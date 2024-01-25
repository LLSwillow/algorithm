#include <iostream>
using namespace std;

const int N = 1e5 + 10, P = 131;
typedef unsigned long long ULL;

int n, m;
char str[N];
ULL ha[N], p[N]; // ha存储所有子串映射的哈希值  p数组存储 以 P 为进制数 的P的次方，方便加权求和
// ha数组的下标表示的就是前多少个字符  p数组的下标表示的就是对应多少次方

ULL get(int l, int r)
{
    return ha[r] - ha[l - 1] * p[r - l + 1];
}
int main()
{
    scanf("%d%d%s", &n, &m, str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        ha[i] = ha[i - 1] * P + str[i]; // 加权求值
    }
    while (m--)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}