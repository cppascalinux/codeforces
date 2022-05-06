#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int s[200009];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		int mn=1e9,mx=-1e9;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s+i);
			if(i>1)
				ans+=abs(s[i]-s[i-1]);
			mn=min(mn,s[i]);
			mx=max(mx,s[i]);
		}
		if(mn>1)
		{
			int s1=(mn-1)*2;
			int s2=min(s[1]-1,s[n]-1);
			ans+=min(s1,s2);
		}
		if(mx<m)
		{
			int s1=(m-mx)*2;
			int s2=min(m-s[1],m-s[n]);
			ans+=min(s1,s2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}