#include<bits/stdc++.h>
using namespace std;
int n,tp;
set<int> g[200009];
int f[109],id[200009];
int sz[200009],st[200009];
int anc[200009];
void suc()
{
	printf("YES");
	exit(0);
}
void fail()
{
	printf("NO");
	exit(0);
}
void dfs1(int x,int fa)
{
	st[++tp]=x;
	sz[x]=1;
	anc[x]=fa;
	for(int v:g[x])
		if(v!=fa)
		{
			dfs1(v,x);
			sz[x]+=sz[v];
		}
}
void solve(int x)
{
	// printf("x:%d\n",x);
	tp=0;
	dfs1(x,0);
	if(tp==1)
		return;
	int ps=id[tp];
	if(ps==0)
		fail();
	for(int i=1;i<=tp;i++)
		if(sz[st[i]]==f[ps-1]||sz[st[i]]==f[ps-2])
		{
			int v=st[i],ft=anc[st[i]];
			g[v].erase(ft),g[ft].erase(v);
			// printf("x:%d v:%d ft:%d\n",x,v,ft);
			solve(v);
			solve(ft);
			return;
		}
	fail();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].insert(b);
		g[b].insert(a);
	}
	f[0]=f[1]=1;
	id[1]=1;
	for(int i=2;i<=100;i++)
	{
		f[i]=f[i-1]+f[i-2];
		id[f[i]]=i;
		if(f[i]>n)
			break;
	}
	solve(1);
	suc();
	return 0;
}