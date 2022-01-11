#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int tag[5009],s[5009];
ll f[5009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",tag+i);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		for(int i=1;i<=n;i++)
			f[i]=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
				if(tag[i]!=tag[j])
				{
					ll nf=max(f[j],f[i]+abs(s[i]-s[j]));
					f[i]=max(f[i],f[j]+abs(s[i]-s[j]));
					f[j]=nf;
				}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,f[i]);
		printf("%lld\n",ans);
	}
	return 0;
}