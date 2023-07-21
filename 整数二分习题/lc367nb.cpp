#include <iostream>
using namespace std;
class Solution 
{
public:
    bool isPerfectSquare(int x) 
    {
        int num = 1;
        while(x > 0) 
        {
            x -= num;
            num += 2;
        }
        return x == 0;
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