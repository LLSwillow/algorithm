#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int flag=0;
    int cnt=0;

    for(int y=1921;y<=2020;y++)
    {
        for(int m=1;m<=12;m++)
        {
            for(int d=1;d<=31;d++)
            {
                if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12);
                else if(m==2)
                {
                    if((y%4==0&&y%100!=0) || y%400==0)
                    {
                        if(d>29)break;
                    }
                    else {
                        if(d>28)break;
                    }
                }
                else {
                    if(d>30)break;
                }
                if(y==1921 && m==7 && d==23)flag=1;
                if(flag)cnt+=1440;
                if(y==2020 && m==7 && d==1)
				{
					cout<<cnt-1440;
					return 0;
				}
            }
        }
    }
    return 0;
}
