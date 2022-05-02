#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k;
ll s[300009];
ll d[300009];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",s+i);
	ll ans=0,mn=0,dt=0;
	for(int i=n;i>=1;i--)
	{
		mn+=dt;
		s[i]+=mn;
		dt+=d[i];
		if(i>=k&&s[i]>0)
		{
			ll t=(s[i]+k-1)/k;
			ans+=t;
			mn+=-k*t;
			dt+=t;
			s[i]-=k*t;
			d[i-k]-=t;
		}
	}
	// printf("ans:%lld\n",ans);
	// for(int i=1;i<=n;i++)
	// 	printf("%lld ",s[i]);
	// printf("\n");
	ll tmp=0;
	for(int i=1;i<=k;i++)
		if(s[i]>0)
			tmp=max(tmp,(s[i]+i-1)/i);
	ans+=tmp;
	printf("%lld",ans);
	return 0;
}