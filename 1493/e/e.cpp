#include<bits/stdc++.h>
using namespace std;
int n;
char sl[1000009],sr[1000009];
int main()
{
	scanf("%d",&n);
	scanf("%s%s",sl+1,sr+1);
	for(int i=1;i<=n;i++)
		sl[i]-='0',sr[i]-='0';
	int fg=0;
	for(int i=1;i<=n;i++)
		if(sl[i]!=sr[i])
		{
			fg=i;
			break;
		}
	if(!fg)
	{
		for(int i=1;i<=n;i++)
			printf("%d",sl[i]);
		return 0;
	}
	if(fg==1)
	{
		for(int i=1;i<=n;i++)
			printf("1");
		return 0;
	}
	int all1=1;
	int tg=0;
	for(int i=fg+1;i<=n;i++)
		if(sr[i])
			tg=1;
	if(tg&&sr[n]==1)
	{
		for(int i=1;i<=n;i++)
			printf("%d",sr[i]);
		return 0;
	}
	if(tg&&sr[n]==0&&sr[n-1]==1)
	{
		sr[n]=1;
		for(int i=1;i<=n;i++)
			printf("%d",sr[i]);
		return 0;
	}
	int lg=1;
	for(int i=fg+1;i<=n;i++)
		if(!sl[i])
			lg=0;
	if(tg&&sr[n]==0&&!lg)
	{
		sr[n]=1;
		for(int i=1;i<=n;i++)
			printf("%d",sr[i]);
		return 0;
	}
	if(tg)
	{
		for(int i=1;i<=n;i++)
			printf("%d",sr[i]);
		return 0;
	}
	if(lg)
	{
		for(int i=1;i<=n;i++)
			printf("%d",sr[i]);
		return 0;
	}
	for(int i=1;i<=fg;i++)
		printf("%d",sr[i]);
	for(int i=fg+1;i<=n-1;i++)
		printf("0");
	printf("1");
	return 0;
}