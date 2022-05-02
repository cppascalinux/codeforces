#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int h[300009],s[300009];
ll solve()
{
	ll sm1=0,sm2=0;
	for(int i=1;i<=n;i++)
		sm1+=s[i]%2,sm2+=s[i]/2;
	if(sm1>sm2)
		return sm1*2-1;
	if(sm1==sm2)
		return sm1*2;
	if(sm1==sm2-1)
		return sm2*2;
	ll k=(sm2-sm1+1)/3;
	sm2-=k;
	sm1+=2*k;
	if(sm1>sm2)
		return sm1*2-1;
	if(sm1==sm2)
		return sm1*2;
	if(sm1==sm2-1)
		return sm2*2;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		int mx=0;
		for(int i=1;i<=n;i++)
			scanf("%d",h+i),mx=max(mx,h[i]);
		for(int i=1;i<=n;i++)
			s[i]=mx-h[i];
		ll ans=solve();
		for(int i=1;i<=n;i++)
			s[i]=mx-h[i]+1;
		ans=min(ans,solve());
		printf("%lld\n",ans);
	}
	return 0;
}