#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n;
vector<int> e[100009];
int f[100009][2];
int deg[100009];
int fat[100009];
vector<int> g[100009][2];
vector<pii> del,add;
int qv[100009];
void dfs(int x,int fa)
{
	int sm=0;
	for(int v:e[x])
		if(v!=fa)
		{
			dfs(v,x);
			sm+=f[v][0];
		}
	f[x][0]=f[x][1]=sm+1;
	vector<pii> s;
	for(int v:e[x])
		if(v!=fa)
			s.emplace_back(f[v][1]-f[v][0]-1,v);
	sort(s.begin(),s.end());
	if(!s.empty())
	{
		if(s[0].fi<0)
		{
			f[x][1]+=s[0].fi,g[x][1].push_back(s[0].se);
			f[x][0]+=s[0].fi,g[x][0].push_back(s[0].se);
		}
		if(s.size()>1&&s[1].fi<0)
			f[x][0]+=s[1].fi,g[x][0].push_back(s[1].se);
	}
}
int fnd(int x)
{
	return x==fat[x]?x:fat[x]=fnd(fat[x]);
}
void dfs2(int x,int fa,int vl)
{
	int v1=0,v2=0;
	if(g[x][vl].size())
	{
		v1=g[x][vl][0];
		deg[x]++;
		deg[v1]++;
		fat[fnd(v1)]=fnd(x);
	}
	if(g[x][vl].size()>1)
	{
		v2=g[x][vl][1];
		deg[x]++;
		deg[v2]++;
		fat[fnd(v2)]=fnd(x);
	}
	for(int v:e[x])
		if(v!=fa)
		{
			if(v==v1||v==v2)
				dfs2(v,x,1);
			else
			{
				del.emplace_back(x,v);
				dfs2(v,x,0);
			}
		}
}
void solve()
{
	dfs(1,0);
	for(int i=1;i<=n;i++)
		fat[i]=i;
	dfs2(1,0,0);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d fnd:%d\n",i,fnd(i));
	int x=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==1)
			qv[fnd(i)]^=i;
		if(deg[i]<=1)
			x=i;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]<=1&&fnd(i)!=fnd(x))
		{
			add.emplace_back(i,x);
			int t=qv[fnd(i)]^i;
			fat[fnd(i)]=fnd(x);
			x=t;
		}
	int ans=f[1][0]-1;
	printf("%d\n",ans);
	// printf("ans:%d del:%d add:%d\n",ans,del.size(),add.size());
	assert(del.size()==ans);
	assert(add.size()==ans);
	for(int i=0;i<ans;i++)
		printf("%d %d %d %d\n",del[i].fi,del[i].se,add[i].fi,add[i].se);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			deg[i]=0;
			fat[i]=i;
			g[i][0].clear();
			g[i][1].clear();
			qv[i]=0;
		}
		del.clear(),add.clear();
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		solve();
	}
	return 0;
}