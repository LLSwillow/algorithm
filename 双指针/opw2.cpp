#include <iostream>
using namespace std;
int main()
{
    string a;
    getline(cin, a);
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ')
            continue;
        for (int j = i; j < a.size() && a[j] != ' '; j++)
        {
            cout << a[j];
        }
        cout << endl;
        while (i < a.size() && a[i] != ' ')
            i++; // j在其自身循环内部定义，循环结束之后j就被销毁，所以我们要重新找
    }
    return 0;
}