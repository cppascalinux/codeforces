#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
int n;
int deg[100009],vis[100009];
vector<int> e[100009];
int a1[100009],a2[100009];
int p[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll ans=0;
		e[1].push_back(n),e[n].push_back(1);
		ans+=(ll)(n-1)*(n-1);
		for(int i=n/2+1;i<=n-1;i++)
			e[1].push_back(i),e[i].push_back(1),ans+=(ll)(i-1)*(i-1);
		for(int i=2;i<=n/2;i++)
			e[n].push_back(i),e[i].push_back(n),ans+=(ll)(n-i)*(n-i);
		queue<int> q;
		for(int i=1;i<=n;i++)
			if((deg[i]=e[i].size())==1)
				q.push(i);
		int tp=0;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			vis[x]=1;
			for(int u:e[x])
				if(!vis[u])
				{
					a1[++tp]=x,a2[tp]=u;
					if(--deg[u]==1)
						q.push(u);
				}
			if(tp>=n-1)
				break;
		}
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=n-1;i>=1;i--)
			swap(p[a1[i]],p[a2[i]]);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		printf("\n%d\n",n-1);
		for(int i=1;i<=n-1;i++)
			printf("%d %d\n",a1[i],a2[i]);
		for(int i=1;i<=n;i++)
			e[i].clear(),deg[i]=vis[i]=0;
	}
	return 0;
}