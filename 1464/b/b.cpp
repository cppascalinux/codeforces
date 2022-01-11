#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int x,y,n;
char s[100009];
int sm0[100009],sm1[100009];
int main()
{
	scanf("%s",s+1);
	scanf("%d%d",&x,&y);
	n=strlen(s+1);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		sm0[i]=sm0[i-1];
		sm1[i]=sm1[i-1];
		if(s[i]=='0')
			sm0[i]++,ans+=(ll)y*sm1[i];
		else if(s[i]=='1')
			sm1[i]++,ans+=(ll)x*sm0[i];
	}
	// printf("ans:%lld\n",ans);
	if(x<y)
	{
		ll sm=0,mn=0;
		int tl=0,tp=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='?')
				sm+=(ll)x*sm0[i]+(ll)y*(sm0[n]-sm0[i]),tl++;
		// printf("sm:%lld\n",sm);
		mn=sm;
		for(int i=1;i<=n;i++)
			if(s[i]=='?')
			{
				sm-=(ll)x*sm0[i]+(ll)y*(sm0[n]-sm0[i]);
				sm+=(ll)y*sm1[i]+(ll)x*(sm1[n]-sm1[i]);
				sm-=(ll)x*tp;
				tp++;
				sm+=(ll)x*(tl-tp);
				mn=min(mn,sm);
			}
		printf("%lld",ans+mn);
	}
	else
	{
		ll sm=0,mn=0;
		int tl=0,tp=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='?')
				sm+=(ll)y*sm1[i]+(ll)x*(sm1[n]-sm1[i]),tl++;
		mn=sm;
		// printf("sm:%lld\n",sm);
		for(int i=1;i<=n;i++)
			if(s[i]=='?')
			{
				sm-=(ll)y*sm1[i]+(ll)x*(sm1[n]-sm1[i]);
				sm+=(ll)x*sm0[i]+(ll)y*(sm0[n]-sm0[i]);
				sm-=(ll)y*tp;
				tp++;
				sm+=(ll)y*(tl-tp);
				// printf("i:%d sm:%lld\n",i,sm);
				mn=min(mn,sm);
			}
		printf("%lld",ans+mn);
	}
	return 0;
}