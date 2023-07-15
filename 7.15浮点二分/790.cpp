#include <iostream>
#include <cmath>
using namespace std;
double n;
int main()
{
    cin >> n;
    double ans = -1; // 倘若输出-1 表示没有找到答案(也就是当输入的n不满足题目要求的时候)
    for (double i = -10000; i <= 10000; i += 1e-6)
    {
        if (fabs(i * i * i - n) < 1e-6)
        {
            ans = i;
            break;
        }
    }
    printf("%.6lf\n", ans);
    return 0;
}
/*
#include<iostream>
using namespace std;
double n;
int main()
{
    cin>>n;
    for(double i=-10000;i<10000;i++)
    {
        if(i*i*i==n)
        {
            printf("%.6lf",i);
        }
    }
    return 0;
}
*/