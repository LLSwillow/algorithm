#include <iostream>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;
        long long l = 0, r = x; // 避免溢出当l r需要做加法的时候
        while (l < r)
        {
            long long mid = l + (r - l + 1) / 2;
            // int mid = (l + r + 1ll) / 2;
            // 这里1ll直接把将整个表达式的类型提升为 long long 避免了溢出 倘若这样写，那么前面l r也不需要定义longlong了
            if (mid <= x / mid)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
int main()
{
    int x;
    Solution s;
    int ans = s.mySqrt(x);
    cout << ans << endl;
    return 0;
}