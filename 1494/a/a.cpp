#include<bits/stdc++.h>
using namespace std;
int n;
char s[109];
int p[109];
int judge()
{
	int sm=0;
	for(int i=1;i<=n;i++)
		if((sm+=p[i])<0)
			return 0;
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int sm[4]={0,0,0,0};
		for(int i=1;i<=n;i++)
			s[i]-='A'-1;
		for(int i=1;i<=n;i++)
			sm[s[i]]++;
		int tp=0;
		for(int i=1;i<=3;i++)
			if(sm[i]==n/2)
				tp=i;
		if(!tp)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			if(s[i]==tp)
				p[i]=1;
			else
				p[i]=-1;
		if(judge())
		{
			printf("YES\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			if(s[i]==tp)
				p[i]=-1;
			else
				p[i]=1;
		if(judge())
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}