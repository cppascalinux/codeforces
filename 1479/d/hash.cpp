#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
#include<vector>
#define ull unsigned long long
using namespace std;
int n,m,tot;
int vl[300009];
vector<int> g[300009];
int f[300009][20],dep[300009];
ull hs[300009];
int rt[300009];
int ls[6000009],rs[6000009];
ull sm[6000009];
mt19937_64 rnd(20020618LL*20030619LL);
void add(int &a,int l,int r,int p,ull v)
{
	int t=++tot;
	ls[t]=ls[a],rs[t]=rs[a],sm[t]=sm[a];
	a=t;
	sm[a]^=v;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(p<=mid)
		add(ls[a],l,mid,p,v);
	else
		add(rs[a],mid+1,r,p,v);
}
void dfs(int x,int fa)
{
	f[x][0]=fa;
	for(int i=1;i<=19;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	dep[x]=dep[fa]+1;
	rt[x]=rt[fa];
	add(rt[x],1,n,vl[x],hs[vl[x]]);
	for(int u:g[x])
		if(u!=fa)
			dfs(u,x);
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
int qry(int a,int b,int v,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql)
		return -1;
	int mid=(l+r)>>1;
	int la=ls[a],lb=ls[b];
	int ra=rs[a],rb=rs[b];
	if(l>=ql&&r<=qr)
	{
		ull h=v>=l&&v<=r?hs[v]:0;
		if((sm[a]^sm[b]^h)==0)
			return -1;
		if(l==r)
			return l;
		ull lh=v>=l&&v<=mid?hs[v]:0;
		if(sm[la]^sm[lb]^lh)
			return qry(la,lb,v,l,mid,ql,qr);
		return qry(ra,rb,v,mid+1,r,ql,qr);
	}
	int lans=qry(la,lb,v,l,mid,ql,qr);
	int rans=qry(ra,rb,v,mid+1,r,ql,qr);
	if(lans==-1&&rans==-1)
		return -1;
	if(lans==-1||rans==-1)
		return lans+rans+1;
	return lans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",vl+i);
	for(int i=1,a,b;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		g[a].push_back(b),g[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		hs[i]=rnd();
	dfs(1,0);
	for(int i=1,a,b,c,d;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int lca=getlca(a,b);
		printf("%d\n",qry(rt[a],rt[b],vl[lca],1,n,c,d));
	}
	return 0;
}