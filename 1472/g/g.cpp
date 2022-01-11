#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define inf 0x7F7F7F7F
using namespace std;
int n,m,tot,tp,smcl;
int dis[200009],vis[200009];
int dfn[200009],low[200009],ins[200009],st[200009];
int cl[200009],vcl[200009];
int vl[200009],f[200009],deg[200009];
vector<int> g0[200009],g1[200009];
void clr()
{
	tot=tp=smcl=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]=dis[i]=dfn[i]=low[i]=ins[i]=st[i]=0;
		deg[i]=0;
		g0[i].clear(),g1[i].clear();
	}
}
void bfs()
{
	queue<int> q;
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int v:g0[x])
			if(!vis[v])
				vis[v]=1,dis[v]=dis[x]+1,q.push(v);
	}
}
void getvl()
{
	for(int i=1;i<=n;i++)
	{
		vl[i]=dis[i];
		for(int v:g0[i])
			vl[i]=min(vl[i],dis[v]);
	}
}
void dfs(int x)
{
	dfn[x]=low[x]=++tot;
	ins[x]=1;
	st[++tp]=x;
	for(int v:g0[x])
		if(dis[v]>dis[x])
		{
			if(!dfn[v])
				dfs(v),low[x]=min(low[x],low[v]);
			else if(ins[v])
				low[x]=min(low[x],dfn[v]);
		}
	if(dfn[x]==low[x])
	{
		smcl++;
		do
			cl[st[tp--]]=smcl;
		while(st[tp+1]!=x);
	}
	ins[x]=0;
}
void rebuild()
{
	for(int i=1;i<=smcl;i++)
		vcl[i]=inf;
	for(int i=1;i<=n;i++)
	{
		vcl[cl[i]]=min(vcl[cl[i]],vl[i]);
		for(int v:g0[i])
			if(dis[v]>dis[i]&&cl[i]!=cl[v])
				g1[cl[v]].push_back(cl[i]),deg[cl[i]]++;
	}
}
void dp()
{
	queue<int> q;
	for(int i=1;i<=smcl;i++)
		f[i]=vcl[i];
	for(int i=1;i<=smcl;i++)
		if(!deg[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int v:g1[x])
		{
			f[v]=min(f[v],f[x]);
			if(!--deg[v])
				q.push(v);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		clr();
		for(int i=1,a,b;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			g0[a].push_back(b);
		}
		bfs();
		getvl();
		dfs(1);
		rebuild();
		dp();
		// printf("ans:");
		for(int i=1;i<=n;i++)
			printf("%d ",f[cl[i]]);
		printf("\n");
	}
	return 0;
}