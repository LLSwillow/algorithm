#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int y[N],m[N],d[N];
int main()
{
	int a;
	int x=0,sum=0;
	while(cin>>a)
	{
		x++;
		y[x]=a/10000;
		m[x]=a%10000/100;
		d[x]=a%10000%100;
		
		//cout<<y[x]<<" "<<m[x]<<" "<<d[x];
		int flag=0;
		if(x%2==0)
		{
			if (y[x] < y[x - 1] || (y[x] == y[x - 1] && m[x] < m[x - 1]) || (y[x] == y[x - 1] && m[x] == m[x - 1] && d[x] < d[x - 1])) {
                swap(y[x], y[x - 1]);
                swap(m[x], m[x - 1]);
                swap(d[x], d[x - 1]);
            }
            
			if(y[x]==y[x-1] && m[x]==m[x-1] && d[x]==d[x-1]){
				cout<<"1"<<endl;
				continue;
			}
			
			
			for(int i=y[x-1];i<=y[x];i++)
			{
				for(int j=1;j<=12;j++)
				{
					for(int k=1;k<=31;k++)
					{
						if(j==1||j==3||j==5||j==7||j==8||j==10||j==12);
						else if(j==2){
							if(i%400==0 ||(i%4==0 && i%100!=0))
							{
								if(k>29)break;
							}
							else {
								if(k>28)break;
							}
						}
						else {
							if(k>30)break;
						}
						if(i==y[x-1] && j==m[x-1] && k==d[x-1])flag=1;
						if(flag)sum++;
						
						if(i==y[x] && j==m[x] && k==d[x]){
							cout<<sum<<endl;
							sum=0;
							flag=0;
						}
					}
				}
			}
		}
	}
	return 0;
}
