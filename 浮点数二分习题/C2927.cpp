#include <iostream>
using namespace std;
int main()
{
    double y, x;
    y = x * x * x * x * x - 15 * x * x * x * x + 85 * x * x * x - 225 * x * x + 274 * x - 121;
    double l = 1.5, r = 2.4;
    while (r - l > 1e-6)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid * mid * mid - 15 * mid * mid * mid * mid + 85 * mid * mid * mid - 225 * mid * mid + 274 * mid - 121 >= 0)
            l = mid;
        else
            r = mid;
    }
    printf("%.6lf", l);
    return 0;
}