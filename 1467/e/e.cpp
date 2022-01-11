#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,d,cnt;
int s[200009];
vector<int> g[200009],cl[200009];
int ft[200009],vl[200009];
int f[200009][19],dep[200009],dfn[200009],ed[200009];
int ds[200009];
int md[200009];
void lsh()
{
	static int v[200009];
	for(int i=1;i<=n;i++)
		v[i]=s[i];
	sort(v+1,v+n+1);
	d=unique(v+1,v+n+1)-v-1;
	for(int i=1;i<=n;i++)
		s[i]=lower_bound(v+1,v+d+1,s[i])-v;
}
void dfs(int x,int fa)
{
	ed[x]=dfn[x]=++cnt;
	ds[cnt]=x;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=18;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int u:g[x])
		if(u!=fa)
			dfs(u,x),ed[x]=max(ed[x],ed[u]);
	// printf("x:%d dfn:%d ed:%d\n",x,dfn[x],ed[x]);
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	int df=dep[a]-dep[b];
	for(int i=0;i<=18;i++)
		if(df>>i&1)
			a=f[a][i];
	if(a==b)
		return a;
	for(int i=18;i>=0;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
void add(int l,int r,int v)
{
	md[l]+=v,md[r+1]-=v;
	// printf("l:%d r:%d v:%d\n",l,r,v);
}
bool cmp(int a,int b)
{
	return dfn[a]<dfn[b];
}
void fail()
{
	printf("0");
	exit(0);
}
void dfs2(int x,int fa)
{
	for(int u:g[x])
		if(u!=fa)
			dfs2(u,x),md[x]+=md[u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	lsh();
	for(int i=1;i<=n;i++)
		cl[s[i]].push_back(i);
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b),g[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ft[i]=i,vl[i]=1;
	// int ost=0;
	for(int i=1;i<=d;i++)
	{
		if(cl[i].size()==1)
		{
			// ost++;
			continue;
		}
		sort(cl[i].begin(),cl[i].end(),cmp);
		int lst=0,fst=0,u1=0;
		for(int u:cl[i])
		{
			if(lst)
			{
				int lca=getlca(lst,u);
				if(s[lca]==i&&lst!=u1)
					fail();
				if(dep[lca]<dep[fst])
					if(s[fst]==i&&lst!=u1)
						fail();
					else
						fst=lca;
				add(dfn[u],ed[u],1);
			}
			else
				fst=u,u1=u;
			lst=u;
		}
		if(u1!=fst)
			add(dfn[u1],ed[u1],1);
		if(s[fst]==i)
		{
			int df=dep[lst]-dep[fst]-1;
			for(int j=0;j<=18;j++)
				if(df>>j&1)
					lst=f[lst][j];
			add(dfn[lst],ed[lst],-1);
			add(1,n,1);
		}
	}
	// printf("qwq");
	for(int i=2;i<=n;i++)
		md[i]+=md[i-1];
	int ans=0;
	for(int i=1;i<=n;i++)
		// if(cl[s[i]].size()==1)
		{
			if(md[dfn[i]]==0)
				ans++;
		}
	printf("%d",ans);
	return 0;
}