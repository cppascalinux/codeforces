#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int s[200009];
ll f[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		ll ans=0;
		for(int i=n;i>=1;i--)
		{
			if(i+s[i]>n)
				f[i]=s[i];
			else
				f[i]=f[i+s[i]]+s[i];
			ans=max(ans,f[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}