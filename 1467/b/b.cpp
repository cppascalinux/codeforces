#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int s[300009],p[300009];
int judge(int a,int b,int c)
{
	return (b>a&&b>c)||(b<a&&b<c);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		if(n==3)
		{
			printf("0\n");
			continue;
		}
		int sm=0;
		for(int i=2;i<=n-1;i++)
			if(judge(s[i-1],s[i],s[i+1]))
				p[i]=1,sm++;
			else
				p[i]=0;
		p[1]=p[n]=0;
		int ans=sm;
		for(int i=2;i<=n-1;i++)
		{
			int tsm=p[i-1]+p[i]+p[i+1];
			if(tsm==0)
				continue;
			if(tsm==3)
			{
				ans=min(ans,sm-3);
				continue;
			}
			if(i==2)
			{
				// if(judge(s[1],s[3],s[4]))
				// 	ans=min(ans,sm-(tsm-1));
				// else
					ans=min(ans,sm-tsm);
				continue;
			}
			if(i==n-1)
			{
				// if(judge(s[n-3],s[n-2],s[n]))
				// 	ans=min(ans,sm-(tsm-1));
				// else
					ans=min(ans,sm-tsm);
				continue;
			}
			if(tsm==1)
			{
				ans=min(ans,sm-1);
				continue;
			}
			if((s[i-2]>s[i-1]&&s[i-1]<s[i+1]&&s[i+1]>s[i+2])||(s[i-2]<s[i-1]&&s[i-1]>s[i+1]&&s[i+1]<s[i+2]))
			{
				ans=min(ans,sm-1);
				continue;
			}
			ans=min(ans,sm-tsm);
		}
		printf("%d\n",ans);
	}
	return 0;
}