#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n,m,tot;
int vl[300009];
int s[600009],blk[600009];
int lbk[1009],rbk[1009],smbk[1009];
int bg[300009],ed[300009];
int dep[300009];
int f[300009][20];
int rep[300009];
int ans[300009];
vector<int> g[300009];
struct node
{
	int sl,sr,vl,vr,lca,id;
	bool operator<(const node &p)const{return blk[sl]<blk[p.sl]||(blk[sl]==blk[p.sl]&&sr<p.sr);}
}q[300009];
void dfs(int x,int fa)
{
	s[++tot]=vl[x];
	bg[x]=tot;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=19;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int u:g[x])
		if(u!=fa)
			dfs(u,x);
	s[++tot]=vl[x];
	ed[x]=tot;
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	int d=dep[a]-dep[b];
	for(int i=0;i<=19;i++)
		if(d>>i&1)
			a=f[a][i];
	if(a==b)
		return a;
	for(int i=19;i>=0;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
void initblk()
{
	int len=sqrt(tot);
	for(int i=1;i<=tot;i++)
		blk[i]=(i-1)/len+1;
	for(int i=1;i<=tot;i++)
		rbk[blk[i]]=i;
	for(int i=tot;i>=1;i--)
		lbk[blk[i]]=i;
}
void add(int p)
{
	smbk[blk[p]]+=(rep[p]^=1)*2-1;
}
int ask(int l,int r)
{
	if(blk[l]==blk[r])
	{
		for(int i=l;i<=r;i++)
			if(rep[i])
				return i;
		return -1;
	}
	int l1=rbk[blk[l]];
	for(int i=l;i<=l1;i++)
		if(rep[i])
			return i;
	int r1=lbk[blk[r]];
	for(int i=r1;i<=r;i++)
		if(rep[i])
			return i;
	int lb=blk[l]+1,rb=blk[r]-1;
	for(int i=lb;i<=rb;i++)
		if(smbk[i])
		{
			for(int j=lbk[i];j<=rbk[i];j++)
				if(rep[j])
					return j;
		}
	return -1;
}
void solve()
{
	int pl=1,pr=0;
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++)
	{
		node t=q[i];
		while(pr<t.sr)
			add(s[++pr]);
		while(pl>t.sl)
			add(s[--pl]);
		while(pr>t.sr)
			add(s[pr--]);
		while(pl<t.sl)
			add(s[pl++]);
		if(t.lca)
			add(vl[t.lca]);
		// for(int i=1;i<=n;i++)
		// 	printf("i:%d rep:%d\n",i,rep[i]);
		// printf("lca:%d\n",t.lca);
		ans[t.id]=ask(t.vl,t.vr);
		if(t.lca)
			add(vl[t.lca]);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",vl+i);
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b),g[b].push_back(a);
	}
	dfs(1,0);
	// for(int i=1;i<=tot;i++)
	// 	printf("%d ",s[i]);
	// printf("\n");
	initblk();
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int lca=getlca(a,b);
		if(bg[a]>bg[b])
			swap(a,b);
		if(lca==a||lca==b)
			q[i]=node{bg[a],bg[b],c,d,0,i};
		else
			q[i]=node{ed[a],bg[b],c,d,lca,i};
	}
	solve();
	return 0;
}