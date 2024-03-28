#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e5+10;
int s[26][N];
char str[N];
signed main()
{
	/*
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	
	scanf("%s",str+1);
	for(int i=0;i<26;i++)
	{
		for(int j=1;str[j];j++)
		{
			if(str[j]-'a'==i)s[i][j]=s[i][j-1]+1;
			else s[i][j]=s[i][j-1];
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		bool st=1;
		for(int i=0;i<26;i++)
		{
			if(s[i][b]-s[i][a-1]!=s[i][d]-s[i][c-1])
			{
				st=0;
				break;
			}
		}
		if(st)puts("DA");
		else puts("NE"); 
	}
	return 0;
}
