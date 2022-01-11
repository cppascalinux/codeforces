#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,tot,sfg;
ll ans;
int dep[300009],f[300009][19];
int sz[300009],sn[300009];
vector<int> g[300009];
struct node
{
	int u,v,l;
	bool operator<(const node &p)const{return dep[l]<dep[p.l];}
}q[300009];
vector<node> ql[300009],qv[300009];
priority_queue<int> pq[300009];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=18;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int v:g[x])
		if(v!=fa)
			dfs1(v,x);
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	int d=dep[a]-dep[b];
	for(int i=0;i<=18;i++)
		if(d>>i&1)
			a=f[a][i];
	if(a==b)
		return a;
	for(int i=18;i>=0;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
int getdl(int x,int fa)
{
	if(x==fa)
		return ++tot;
	int d=dep[x]-dep[fa]-1;
	for(int i=0;i<=18;i++)
		if(d>>i&1)
			x=f[x][i];
	return x;
}
void dfs2(int x)
{
	sz[x]=qv[x].size();
	for(int v:g[x])
		if(v!=f[x][0])
		{
			dfs2(v);
			sz[x]+=sz[v];
			if(!sn[x]||sz[v]>sz[sn[x]])
				sn[x]=v;
		}
	auto &vs=ql[x];
	tot=n;
	map<int,int> mp1;
	map<pii,int> mp2;
	for(auto it=vs.begin();it!=vs.end();it++)
	{
		it->u=getdl(it->u,it->l);
		it->v=getdl(it->v,it->l);
		if(it->u>it->v)
			swap(it->u,it->v);
		mp1[it->u]++;
		mp1[it->v]++;
		mp2[pii(it->u,it->v)]++;
	}
	ll sm=0;
	for(node t:vs)
	{
		sm+=vs.size();
		sm-=mp1[t.u];
		sm-=mp1[t.v];
		sm+=mp2[pii(t.u,t.v)];
	}
	ans+=sm/2;
	// printf("x:%d sm:%lld\n",x,sm);
}
void dfs3(int x,int fa)
{
	map<int,int> mp1;
	for(node t:ql[x])
	{
		mp1[t.u]++,mp1[t.v]++;
		// printf("x:%d bu:%d bv:%d\n",x,t.u,t.v);
	}
	// ll sm=0;
	vector<int> vs;
	for(int v:g[x])
		if(v!=f[x][0])
		{
			int id=v==sn[x]?fa:v;
			dfs3(v,id);
			while(!pq[id].empty()&&pq[id].top()>=dep[x])
				pq[id].pop();
			ans+=(ll)(ql[x].size()-mp1[v])*pq[id].size();
			// sm+=(ll)(ql[x].size()-mp1[v])*pq[id].size();
			// int t0=ql[x].size()-mp1[v];
			// int t1=pq[id].size();
			// printf("x:%d v:%d t0:%d t1:%d\n",x,v,t0,t1);
			if(v!=sn[x])
				while(!pq[id].empty())
					vs.push_back(pq[id].top()),pq[id].pop();
		}
	for(int t:vs)
		pq[fa].push(t);
	for(node t:qv[x])
	{
		if(dep[t.l]>=dep[x])
			continue;
		pq[fa].push(dep[t.l]);
		ans+=ql[x].size();
		// sm+=ql[x].size();
	}
	// auto tmp=pq[fa];
	// while(!tmp.empty())
	// {
	// 	node t=tmp.top();
	// 	tmp.pop();
	// 	printf("x:%d fa:%d u:%d v:%d l:%d\n",x,fa,t.u,t.v,t.l);
	// }
	// printf("x:%d sm:%lld\n",x,sm);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		// if(i==1&&a==38275&&b==213178)
		// 	sfg=1;
		g[a].push_back(b),g[b].push_back(a);
	}
	dfs1(1,0);
	if(sfg)
	{
		int mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,dep[i]);
		// printf("mx:%d\n",mx);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].u,&q[i].v);
		q[i].l=getlca(q[i].u,q[i].v);
		// printf("u:%d v:%d l:%d\n",q[i].u,q[i].v,q[i].l);
		ql[q[i].l].push_back(q[i]);
		if(q[i].u!=q[i].l)
			qv[q[i].u].push_back(q[i]);
		if(q[i].v!=q[i].l)
			qv[q[i].v].push_back(q[i]);
	}
	dfs2(1);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d sz:%d\n",i,sz[i]);
	if(!sfg)
		dfs3(1,1);
	printf("%lld",ans);
	// printf("\n%d",getdl(3,8));
	return 0;
}