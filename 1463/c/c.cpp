#include<bits/stdc++.h>
#define ll long long
#define inf 0x7F7F7F7F7F7F7F7FLL
using namespace std;
int n;
ll t[100009],x[100009];
int main()
{
	int ts;
	scanf("%d",&ts);
	while(ts--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",t+i,x+i);
		t[n+1]=inf;
		ll cur=0,gl=inf,ans=0,dr=0;
		for(int i=1;i<=n;i++)
		{
			if(gl==inf)
				gl=x[i];
			dr=(gl-cur)>0?1:-1;
			ll te=min(abs(gl-cur),t[i+1]-t[i]);
			ll st=cur,ed=cur+te*dr;
			if(st>ed)
				swap(st,ed);
			if(x[i]>=st&&x[i]<=ed)
				ans++;
			if((cur+=dr*te)==gl)
				gl=inf;
		}
		printf("%lld\n",ans);
	}
	return 0;
}