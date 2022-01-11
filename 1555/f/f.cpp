#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
struct edge
{
	int u,v,x;
};
int n,m,tot;
int ft[300009][20];
int dep[300009];
int f[300009];
edge e[500009];
int vis[500009];
vector<pii> g[300009];
int cl[300009],dfn[300009],lst[300009],id[300009];
int smt[300009];
int ans[500009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
void dfs(int x,int fa)
{
	dfn[x]=lst[x]=++tot;
	id[tot]=x;
	dep[x]=dep[fa]+1;
	ft[x][0]=fa;
	for(int i=1;i<=19;i++)
		ft[x][i]=ft[ft[x][i-1]][i-1];
	for(pii t:g[x])
		if(t.fi!=fa)
		{
			cl[t.fi]=cl[x]^t.se;
			dfs(t.fi,x);
			lst[x]=max(lst[x],lst[t.fi]);
		}
}
void addv(int p,int v)
{
	for(;p;p-=p&-p)
		smt[p]+=v;
}
int askv(int p)
{
	int ans=0;
	for(;p<=n;p+=p&-p)
		ans+=smt[p];
	return ans;
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b])	
		swap(a,b);
	int l=dep[a]-dep[b];
	for(int i=0;i<=19;i++)
		if(l>>i&1)
			a=ft[a][i];
	if(a==b)
		return a;
	for(int i=19;i>=0;i--)
		if(ft[a][i]!=ft[b][i])
			a=ft[a][i],b=ft[b][i];
	return ft[a][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].x);
		int fu=fnd(e[i].u),fv=fnd(e[i].v);
		if(fu!=fv)
		{
			vis[i]=1;
			ans[i]=1;
			f[fu]=fv;
			g[e[i].u].emplace_back(e[i].v,e[i].x);
			g[e[i].v].emplace_back(e[i].u,e[i].x);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i,0);
	for(int i=1;i<=m;i++)
		if(!vis[i])
		{
			int u=e[i].u,v=e[i].v,x=e[i].x;
			if((cl[u]^cl[v]^x)==0)
			{
				ans[i]=0;
				continue;
			}
			int lca=getlca(u,v);
			int sm=askv(dfn[u])+askv(dfn[v])-2*askv(dfn[lca]);
			if(sm==0)
			{
				ans[i]=1;
				for(;u!=lca;u=ft[u][0])
				{
					addv(lst[u],1);
					addv(dfn[u]-1,-1);
				}
				for(;v!=lca;v=ft[v][0])
				{
					addv(lst[v],1);
					addv(dfn[v]-1,-1);
				}
			}
			else
				ans[i]=0;
		}
	for(int i=1;i<=m;i++)
		printf("%s\n",ans[i]?"YES":"NO");
	return 0;
}