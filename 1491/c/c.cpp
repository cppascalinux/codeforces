#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int s[5009];
int lz[5009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),lz[i]=0;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i==n)
			{
				ans+=max(0,s[i]-lz[i]-1);
				break;
			}
			for(int j=i+2;j<=i+s[i]&&j<=n;j++)
				lz[j]++;
			int ns=s[i]-lz[i];
			if(ns<1)
				lz[i+1]+=1-ns;
			ans+=max(ns-1,0);
		}
		printf("%lld\n",ans);
	}
	return 0;
}