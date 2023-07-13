#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int find(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right) // 左闭右开 right本身并不在范围内
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid; // 由于right本身并不在范围内，所以如果再-1，就会导致范围内少了mid-1这个数
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1; // 扫描完整个范围都没有return 说明该数组中没有这个数
    }
};
int main()
{
    solution s1;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    int ans = s1.find(nums, target);
    cout << ans << endl;
    return 0;
}