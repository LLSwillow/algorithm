#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int find(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) // 循环出口是 查找范围是否为空
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
int main()
{
    solution s1;
    int n;
    cin >> n;
    // 输入所需查找数组
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // 输入target
    int target;
    cin >> target;
    int ans = s1.find(nums, target);
    cout << ans << endl;
    return 0;
}