#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long
using namespace std;
int n;
int s[100009];
int bg[100009],ed[100009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	int lst=1,ans=0,tp=0;
	for(int i=2;i<=n+1;i++)
	{
		if(s[i]!=s[i-1])
		{
			int len=i-lst;
			if(len>=2)
			{
				bg[++tp]=lst;
				ed[tp]=i-1;
			}
			lst=i;
		}
	}
	if(tp<=1)
	{
		printf("%d",n);
		return 0;
	}
	set<int> p;
	ans=2;
	for(int i=2;i<=tp;i++)
	{
		if(s[bg[i]]!=s[bg[i-1]])
		{
			ans+=2;
			ans+=bg[i]-ed[i-1]-1;
			continue;
		}
		ans+=2;
		ans+=bg[i]-ed[i-1]-1;
		int c=s[bg[i]];
		if((bg[i]-ed[i-1]-1)%2==1)
		{
			int fg=1;
			for(int j=bg[i]-2;j>=ed[i-1]+2;j-=2)
				if(s[j]!=c)
					fg=0;
			ans-=fg;
		}
	}
	ans+=bg[1]-1;
	ans+=n-ed[tp];
	// if(bg[1]==3&&s[1]==s[3])
	// 	ans+=1;
	// else
	// 	ans+=bg[1]-1;
	// if(ed[tp]==n-2&&s[n]==s[n-2])
	// 	ans+=1;
	// else
	// 	ans+=n-ed[tp];
	printf("%d",ans);
	return 0;
}