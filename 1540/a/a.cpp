#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int dis[100009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",dis+i);
		sort(dis+1,dis+n+1);
		ll ans=dis[n],sm=0;
		for(int i=1;i<=n;i++)
		{
			ll tmp=(ll)(i-1)*dis[i]-sm;
			ans-=tmp;
			sm+=dis[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}