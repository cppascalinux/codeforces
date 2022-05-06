#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int s[200009];
ll sm[200009];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		sort(s+1,s+n+1);
		for(int i=1;i<=n;i++)
			sm[i]=sm[i-1]+s[i];
		int cur=0,tm=0;
		for(int i=1;i<=n;i++)
			if(sm[i]<=m)
				cur=i;
		if(cur==0)
		{
			printf("0\n");
			continue;
		}
		ll ans=0;
		while(cur>0)
		{
			if(m<sm[cur])
				cur--;
			else
			{
				int ntm=(m-sm[cur])/cur+1;
				ans+=(ll)(ntm-tm)*cur;
				tm=ntm;
				cur--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}