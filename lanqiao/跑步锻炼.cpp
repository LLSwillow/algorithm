#include <iostream>
using namespace std;
int main()
{
  int x=0,z=0,sum=0;
  for(int y=2000;y<=2020;y++)
  {
    for(int m=1;m<=12;m++)
    {
      for(int d=1;d<=31;d++)
      {
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12);
        else if(m==2)
        {
          if((y%4==0 && y%100!=0)|| y%400==0)
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
        
        x++;
        if(d==1 || x%7==2)z++;

        if(y==2020 && m==10 && d==1)
		    {
          sum=x+z;
          cout<<sum;
          break;
		}
      }
    }
  }
  return 0;
}
