// 注意点在 函数返回类型
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target) // 函数返回值是一个数组
    {
        vector<int> range(2, -1);
        int n = nums.size();
        // 记得判断数组是否为空
        if (n == 0)
            return range;
        // 找左边界
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] != target)
        {
            return range;
        }
        else
        {
            range[0] = l;
            // 找右边界
            l = 0, r = n - 1;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (nums[mid] <= target)
                    l = mid;
                else
                    r = mid - 1;
            }
            range[1] = l;
            return range;
        }
    }
};
int main()
{
    int n; // 元素个数
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // 由于这里通过下标访问了数组中的元素，所以上面的数组要初始化元素个数，否则可能出错
    }
    int target;
    cin >> target;
    Solution s;
    vector<int> range = s.searchRange(nums, target);
    for (int i = 0; i < 2; i++)
    {
        cout << range[i] << " ";
    }
    return 0;
}