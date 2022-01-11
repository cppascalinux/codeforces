#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[109];
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(n%2==1)
		{
			printf("NO\n");
			continue;
		}
		if(s[1]==')'||s[n]=='(')
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}