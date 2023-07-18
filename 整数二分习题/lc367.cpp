#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int l = 0, r = num;
        while (l < r)
        {
            int mid = (l + r + 1ll) / 2; // 4 2
            if (mid <= num / mid)
                l = mid; // 4
            else
                r = mid - 1; // 3
        }
        // cout<<l<<endl;
        if (l * l < num)
            return false;
        else
            return true;

        /*
        if(l==num/l && num%l==0)return true;
        else return false;
        */
    }
};
int main()
{
    int x;
    cin >> x;
    Solution s;
    bool ans = s.isPerfectSquare(x);
    cout << ans << endl;
    return 0;
}