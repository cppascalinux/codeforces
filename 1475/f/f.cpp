#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[1009];
int m1[1009][1009];
int sr[1009],sc[1009];
int tst(int v)
{
	for(int j=1;j<=n;j++)
		sc[j]=m1[1][j]^v;
	for(int i=1;i<=n;i++)
		sr[i]=m1[i][1]^sc[1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(m1[i][j]^sr[i]^sc[j])
				return 0;
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=n;j++)
				m1[i][j]=s[j]-'0';
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=n;j++)
				m1[i][j]^=(s[j]-'0');
		}
		if(tst(0)||tst(1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}