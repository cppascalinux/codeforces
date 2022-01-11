#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll gcd(ll a,ll b)
{
	if(!b||!a)
		return a+b;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,sm=1;
		ll ans=0;
		scanf("%lld",&n);
		for(ll i=2;sm<=n;i++)
		{
			ll g=gcd(i,sm);
			if(g==i)
				continue;
			ll tsm=sm/g*i;
			// printf("tsm:%lld\n",tsm);
			ll rp=n/tsm,rm=n%tsm;
			ll tot=(i/g-1)*rp;
			tot+=rm/sm;
			// printf("i:%lld tsm:%lld rp:%lld rm:%lld tot:%lld\n",i,tsm,rp,rm,tot);
			ans=(ans+tot%mod*i)%mod;
			sm=tsm;
		}
		printf("%lld\n",ans);
	}
	return 0;
}