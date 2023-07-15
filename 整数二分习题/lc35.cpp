// 注意点在函数插入的位置
// 二分的过程要么直接找到了target，要么就是找到了离mid最近的那个元素
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return 1;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        } // 循环终止的时候 l>r
        // 在l>r的上一步，l=r继续循环，倘若nums[mid]>target，这时说明我们所需要的下标应该插到mid处，r=mid-1导致了l>r，那么l是=mid的
        // 倘若是因为nums[mid]<target,这时说明我们所需要的下标应该插到mid+1处，l=mid+1,导致了l>r，那么l=mid+1的
        return l;

        // 数组中不存在这个数，将其插入   我们并不需要将他插入，只是想知道插入的位置
        /*
        l=0,r=n-1;
        while(l<r)
        {
            int mid=l+r>>1;
            if(nums[mid]>=target)r=mid;
            else l=mid+1;
        }
        if(l=n-1) return l+1;//末尾插入
        else if(l<n-1) return l;//数组中插入
        else
        */
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    Solution s;
    int ans = s.searchInsert(nums, target);
    cout << ans << endl;
    return 0;
}