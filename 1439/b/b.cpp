#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,k;
int deg[100009],vis[100009];
vector<int> g[100009];
vector<int> tmp;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			g[i].clear(),deg[i]=vis[i]=0;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			deg[a]++,deg[b]++;
			g[a].push_back(b),g[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
			g[i].push_back(n+1),sort(g[i].begin(),g[i].end());
		set<pii> s;
		for(int i=1;i<=n;i++)
			s.insert(pii(deg[i],i));
		while(1)
		{
			if(!s.size())
				break;
			if(s.begin()->fi>=k)
				break;
			if(s.begin()->fi==k-1)
			{
				pii t=*s.begin();
				tmp.clear();
				// printf("x:%d\n",t.se);
				tmp.push_back(t.se);
				for(int v:g[t.se])
					if(v<=n&&!vis[v])
						tmp.push_back(v);
				int fg=1;
				for(int i:tmp)
				{
					for(int j:tmp)
						if(i!=j&&*lower_bound(g[i].begin(),g[i].end(),j)!=j)
						{
							fg=0;
							break;
						}
					if(!fg)
						break;
				}
				if(fg)
					break;
			}
			pii t=*s.begin();
			s.erase(s.begin());
			vis[t.se]=1;
			for(int v:g[t.se])
				if(v<=n&&!vis[v])
				{
					s.erase(pii(deg[v],v));
					deg[v]--;
					s.insert(pii(deg[v],v));
				}
		}
		if(s.size())
		{
			if(s.begin()->fi>=k)
			{
				printf("1 %d\n",(int)s.size());
				for(pii t:s)
					printf("%d ",t.se);
			}
			else
			{
				printf("2\n");
				for(int v:tmp)
					printf("%d ",v);
			}
			printf("\n");
		}
		else
			printf("-1\n");
	}
	return 0;
}