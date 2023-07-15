#include <iostream>
using namespace std;
int x;
int main()
{
    cin >> x;
    int l = 0, r = x;
    while (l < r) // 由于整数二分，mid会向下取整，即2.多变成2，应该尽力向左找，我们应查找最后一个使得x平方成立的数
    {
        int mid = (l + r + 1) / 2;
        if (mid <= x / mid)
            l = mid; // 倘若这里写成>= 意思是查找第一个大于等于该数平方根的数,当x=8,只有3符合，所以不是我们想要的
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}