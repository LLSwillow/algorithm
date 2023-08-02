#include <iostream>
using namespace std;
const int N = 50010;
int length, n, m, a[N];

bool check(int x)
{
	// 遍历所有两石头间的距离，确保x是最小距离
	int start = 0, count = 0; // 最开始的位置 就是与起点石头的距离，所以start初始值为0
	for (int i = 1; i <= n + 1; i++)
	{
		if (a[i] - start < x)
			count++;
		else
			start = a[i]; // 更新起始位置
	}
	return count <= m;
}

int find(int l, int r)
{
	// 会有很多满足<=m条件的最小距离，但我们要通过二分来找到最后一个满足<=m条件的最小距离，即最小距离的最大值
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid))
		{
			l = mid;
		}
		else
			r = mid - 1;
	}
	return l;
}
int main()
{
	cin >> length >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	a[n + 1] = length;
	int ans = find(0, length); // 最小距离的初始范围应该包括整个长度，才能确保我们想要的结果一定在区间中
	cout << ans;
	return 0;
}