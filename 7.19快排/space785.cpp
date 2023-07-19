#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], p[N], q[N];
int n;
void mysort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int x = a[l];
    int j = 0, k = 0;
    for (int i = l + 1; i <= r; i++) // l+1是为了把基准数字排除出去
    {
        if (a[i] <= x)
            p[j++] = a[i];
        else
            q[k++] = a[i];
    }
    for (int i = 0; i < j; i++)
    {
        a[l + i] = p[i]; // 为了避免元素错误覆盖，应该从l+i开始放回到a中
    }
    a[l + j] = x; // 把基准元素插到二者之间
    for (int i = 0; i < k; i++)
    {
        a[l + j + 1 + i] = q[i];
    }
    mysort(a, l, l + j - 1);
    mysort(a, l + j + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    mysort(a, l, r);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

/*
#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],p[N],q[N];
int n;
void mysort(int a[],int l,int r)
{
    if(l>=r)return;
    int x=a[l];
    int j=0,k=0;
    for(int i=l;i<=r;i++)
    {
        if(a[i]<=x)p[j++]=a[i];
        else q[k++]=a[i];
    }
    for(int i=0;i<j;i++)
    {
        a[i]=p[i];
    }
    for(int i=j+1;i<k;i++)
    {
        a[i]=q[i];
    }
    mysort(a,0,j-1);
    mysort(a,0,k-1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int l=0,r=n-1;
    mysort(a,l,r);
    /*
    int j=sizeof(p);
    for(int i=0;i<j;i++)
    {
        a[i]=p[i];
    }
    int k=sizeof(q);
    for(int i=0;i<k;i++)
    {
        a[j++]=q[i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
*/