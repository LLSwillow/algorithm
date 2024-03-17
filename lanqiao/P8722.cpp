#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	cin>>a;
	if(a[0]=='J' && a[1]=='a')cout<<"1 ";
	if(a[0]=='F')cout<<"2 ";
	if(a[0]=='M' && a[2]=='r')cout<<"3 ";
	if(a[0]=='A' && a[1]=='p')cout<<"4 ";
	if(a[0]=='M' && a[2]=='y')cout<<"5 ";
	if(a[0]=='J' && a[1]=='u' && a[2]=='n')cout<<"6 ";
	if(a[0]=='J' && a[1]=='u' && a[2]=='l')cout<<"7 ";
	if(a[0]=='A' && a[1]=='u')cout<<"8 ";
	if(a[0]=='S')cout<<"9 ";
	if(a[0]=='O')cout<<"10 ";
	if(a[0]=='N')cout<<"11 ";
	if(a[0]=='D')cout<<"12 ";
	
	if(a[3]=='0')cout<<a[4]-'0';
	else{
		cout<<a[3]-'0';
		cout<<a[4]-'0';
	}
	return 0;
}
