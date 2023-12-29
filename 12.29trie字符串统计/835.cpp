#include<iostream>
using namespace std;
const int N=1e5+10;
int son[N][26],count[N],idx;
//son是一个二维数组，行表示一个节点，列表示该节点的子节点，最大为26个字母都为其子节点
//count数组记录以特定编号节点所对字符结尾的字符串个数，数组元素个数取决于trie树的节点个数
//idx给每个插入进来的节点分配编号
int n;
char str[N];//表示每次输入的字符串
void Insert(char str[])
{
    int p=0;//从根节点开始
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u])son[p][u]=++idx;
        p=son[p][u];//每次查找的末尾的节点
    }
    count[p]++;//以p节点所对字符结尾的字符串个数
}
int query(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u])return 0;
        p=son[p][u];
    }
    return count[p];
}
int main()
{
    cin>>n;
    while(n--)
    {
        char order[2];
        scanf("%s",order);
        scanf("%s",str);
        if(order[0]=='I')
        {
            Insert(str);
        }
        else if(order[0]=='Q')
        {
            printf("%d\n",query(str));
        }
    }
    return 0;
}