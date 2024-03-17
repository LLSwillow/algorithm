#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
int main()
{
	cin>>n;
	cout<<n<<" ";
	while(n/2)
	{
		n/=2;
		cout<<n<<" ";
	}
	return 0;
}
