#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int s[100009];
vector<int> vl[270009];
vector<int> tp[270009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int bit=0;
		while((1<<bit)<=n)
			bit++;
		for(int i=0;i<(1<<bit);i++)
			vl[i].clear(),tp[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),vl[s[i]].push_back(i);
		ll ans=-1e18;
		for(int i=0;i<=n;i++)
		{
			sort(vl[i].begin(),vl[i].end(),greater<int>());
			if(vl[i].size()>2)
				vl[i].resize(2);
		}
		for(int i=0;i<(1<<bit);i++)
		{
			tp[i]=vl[i];
			for(int j=0;j<bit;j++)
				if(i>>j&1)
				{
					int ns=i^(1<<j);
					// printf("i:%d ns:%d\n",i,ns);
					tp[i].insert(tp[i].end(),tp[ns].begin(),tp[ns].end());
				}
			sort(tp[i].begin(),tp[i].end(),greater<int>());
			int d=unique(tp[i].begin(),tp[i].end())-tp[i].begin();
			tp[i].resize(d);
			if(tp[i].size()>=2)	
			{
				tp[i].resize(2);
				ans=max(ans,(ll)tp[i][0]*tp[i][1]-(ll)k*i);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}