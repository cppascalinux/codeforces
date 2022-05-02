#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int sa[30],sb[30];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",sa+i);
		for(int i=1;i<=n;i++)
			scanf("%d",sb+i);
		for(int i=1;i<=n;i++)
			if(sa[i]>sb[i])
				swap(sa[i],sb[i]);
		ll ans=0;
		for(int i=1;i<=n-1;i++)
			ans+=abs(sa[i]-sa[i+1])+abs(sb[i]-sb[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}