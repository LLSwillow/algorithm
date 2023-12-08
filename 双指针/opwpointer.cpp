// 双指针
#include <iostream>
using namespace std;
int main()
{
    string a;
    getline(cin, a);
    for (int i = 0; i < a.size(); i++)
    {
        int j = i; // j指针每次从i指针的位置开始
        while (j < a.size() && a[j] != ' ')
            j++; // 只要j仍有效，并且不为空格，就++，这样就记录下了每个单词的位置，刚好i作为单词的开始，j作为单词的末尾

        for (int k = i; k < j; k++)
            cout << a[k];
        cout << endl;

        i = j; // 更新i为该单词末尾，刚好最外层for循环会给i++，i指向空格位置，在下一次for循环内部不满足条件，未执行，直接再次i++，使得i指向了新单词的开头
    }
    return 0;
}