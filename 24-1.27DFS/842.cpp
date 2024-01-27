#include <iostream>
using namespace std;
const int N = 10;
int n;
int path[N]; // 用来存储可行的方案
bool st[N];  // st用来标记用过的数字

void dfs(int u)
{
    // u=n表示找到了一种方案
    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", path[i]);
        }
        puts(""); // 换行
        return;   // 这里相当于递归出口
    }
    // 当没有走到最深处的时候
    for (int i = 1; i <= n; i++) // 遍历我们有的数字
    {
        if (!st[i]) // 当该数字并没有被用过的时候
        {
            path[u] = i;  // 就可以将其加入路径中
            st[i] = true; // 同时更改标记
            dfs(u + 1);   // 加入一步之后，继续深搜，找更深层的下一步
            st[i] = 0;    ////当找完之后，逐层回溯，将用过的点重新置为0
            // 直到到达一个for循环，也就是i没有被选完的节点，即有多条路径的节点处，会继续执行if语句来得到其他的路径
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(0); // 从根节点开始深搜
    return 0;
}