#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
int main()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		string a=to_string(i);
		int b=a.size();
		switch(b){
			case 1:
				if(a[0]=='2' || a[0]=='1' || a[0]=='9')
				{
					sum+=stoi(a);
				}
				break;
			case 2:
				if(a[0]=='2' || a[0]=='1' || a[0]=='9')
				{
					sum+=stoi(a);
				}
				else if(a[1]=='2' || a[1]=='0' || a[1]=='1' || a[1]=='9')
				{
					sum+=stoi(a);
				}
				break;
			case 3:
				if(a[0]=='2' || a[0]=='1' || a[0]=='9')
				{
					sum+=stoi(a);
				}
				else if(a[1]=='2' || a[1]=='0' || a[1]=='1' || a[1]=='9')
				{
					sum+=stoi(a);
				}
				else if(a[2]=='2' || a[2]=='0' || a[2]=='1' || a[2]=='9')
				{
					sum+=stoi(a);
				}
				break;
			case 4:
				if(a[0]=='2' || a[0]=='1' || a[0]=='9')
				{
					sum+=stoi(a);
				}
				else if(a[1]=='2' || a[1]=='0' || a[1]=='1' || a[1]=='9')
				{
					sum+=stoi(a);
				}
				else if(a[2]=='2' || a[2]=='0' || a[2]=='1' || a[2]=='9')
				{
					sum+=stoi(a);
				}
				else if(a[3]=='2' || a[3]=='0' || a[3]=='1' || a[3]=='9')
				{
					sum+=stoi(a);
				}
				break;
			case 5:
				sum+=stoi(a);
				break;
		}
	}
	cout<<sum;
	return 0;
}
