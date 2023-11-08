#include<iostream>
using namespace std;
const int N=100010;
int q[N],res[N];
int n;
void merge_sort(int q[],int l,int r)
{
    if(l>=r)return;
    int mid=(l+r)/2;

    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    int k=0;//作为答案数组的下标
    int i=l,j=mid+1;//作为两个排好序的序列的下标
    while(i<=mid && j<=r)
    {
        if(q[i]<=q[j])res[k++]=q[i++];
        else res[k++]=q[j++];
    }
    while(i<=mid)res[k++]=q[i++];
    while(j<=r)res[k++]=q[j++];

    for(i=l,j=0;i<=r;i++,j++)
    {
        q[i]=res[j];
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }

    merge_sort(q,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d ",q[i]);
    }
    return 0;
}
