#include<iostream>
using namespace std;
const int N=50010;
int s[26][N];
char str[N];
int q;
int main()
{
	scanf("%s",str+1);
	//处理前缀和
	for(int i=0;i<26;i++)
	{
		for(int j=1;str[j];j++)
		{
			if(str[j]-'a'==i)s[i][j]=s[i][j-1]+1;
			else s[i][j]=s[i][j-1];
		}
	}
	cin>>q;
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		bool flag=1;
		for(int i=0;i<26;i++)
		{
			if(s[i][b]-s[i][a-1]!=s[i][d]-s[i][c-1])
			{
				flag=0;
				break;
			}
		}
		if(flag)puts("DA");
	    else puts("NE");
	}
	return 0;
}
