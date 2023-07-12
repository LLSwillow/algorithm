#include<iostream>
#include<cstring>
using namespace std;
const int N=10000;
int nums[N];
int target,n;
void find(int target,int nums[],int n)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==target)
        {
            k=1;
            cout<<i<<endl;//为了避免有多个目标元素时多次输出下标 添加break
            break;
        }
    }
    if(k==0)cout<<"-1"<<endl;
}
int main()
{
    cin>>n;
    for(int j=0;j<n;j++)
    {
        scanf("%d",&nums[j]);
    }
    printf("target=");
    scanf("%d",&target);
    find(target,nums,n);
    return 0;
}