#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int vis[300009];
vector<int> g[300009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			g[i].clear(),vis[i]=0;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b),g[b].push_back(a);
		}
		queue<int> q1,q2;
		q1.push(1);
		while(!q1.empty())
		{
			int x=q1.front();
			q1.pop();
			if(vis[x])
				continue;
			vis[x]=1;
			for(int v:g[x])
				if(!vis[v])
					vis[v]=2,q2.push(v);
			while(!q2.empty())
			{
				int u=q2.front();
				q2.pop();
				for(int v:g[u])
					if(!vis[v])
						q1.push(v);
			}
		}
		int fg=1,ans=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
				fg=0;
			else if(vis[i]==1)
				ans++;
		if(!fg)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			if(vis[i]==1)
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}