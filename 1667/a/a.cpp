#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int s[5009];
ll v[5009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	ll ans=1e18;
	for(int i=1;i<=n;i++)
	{
		ll sm=0;
		memset(v,0,sizeof(v));
		for(int j=i+1;j<=n;j++)
		{
			ll r=(v[j-1]/s[j])+1;
			sm+=r;
			v[j]=r*s[j];
		}
		for(int j=i-1;j>=1;j--)
		{
			ll r=(v[j+1]/s[j])+1;
			sm+=r;
			v[j]=r*s[j];
		}
		ans=min(ans,sm);
	}
	printf("%lld\n",ans);
	return 0;
}