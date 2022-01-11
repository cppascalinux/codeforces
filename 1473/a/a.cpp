#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d;
int s[1009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		int fg=1;
		for(int i=1;i<=n;i++)
			if(s[i]>d)
				fg=0;
		if(fg)
		{
			printf("YES\n");
			continue;
		}
		sort(s+1,s+n+1);
		if(s[1]+s[2]<=d)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}