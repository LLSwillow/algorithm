#include <iostream>
using namespace std;
const int N = 5010; // 地图最大范围是5000*5000的
int n, r;
int q[N][N];
int main()
{
    cin >> n >> r;
    // 首先要完成的步骤是放炸弹 相当于完成将原数放入数组的步骤.
    r = min(5000, r);
    while (n--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        q[x + 1][y + 1] += w; //+=实现不同目标在同一位置
        // 地图是(0,0)到(5000,5000) 但是由于前缀和算法必须从(1,1)开始，所以我们只能把地图向右下拉
    }
    // 接下来就要实现计算前缀和的过程了
    for (int i = 1; i <= 5001; i++)
    {
        for (int j = 1; j <= 5001; j++)
        {
            q[i][j] = q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1] + q[i][j];
        }
    }
    // 接下来求出所求区域和
    int max1 = 0;
    for (int i = r; i <= 5001; i++) // 这里定义从（r,r）开始，是将(i,j)视为矩阵右下角坐标向左上角拓展区域
    {
        for (int j = r; j <= 5001; j++)
        {
            if (q[i][j] - q[i - r][j] - q[i][j - r] + q[i - r][j - r] > max1)
            {
                max1 = q[i][j] - q[i - r][j] - q[i][j - r] + q[i - r][j - r];
            }
        }
    }
    cout << max1 << endl;
    return 0;
}
