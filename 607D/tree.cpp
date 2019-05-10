//2019.05.10
//CF607D Power Tree 计算贡献+dfs序+树状数组+线段树
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fi first
#define se second
#define pii pair<int,int>
#define mod 1000000007
#define li long long
using namespace std;
int n=1,m,smq,tot,tme;
int v[200009];
pii q[200009];
int hd[200009],eg[200009],nxt[200009];
int f[200009],dfn[200009],ed[200009],deg[200009];
int cp[200009];
int l[800009],r[800009],lz[800009],sm[800009];
void ins(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(li)a*a%mod)
		if(b&1)
			ans=(li)ans*a%mod;
	return ans;
}
void addc(int x,int val)
{
	for(;x;x-=x&-x)
		cp[x]=(li)cp[x]*val%mod;
}
int askc(int x)
{
	int val=1;
	for(;x<=n;x+=x&-x)
		val=(li)val*cp[x]%mod;
	return val;
}
void build(int a,int ll,int rr)
{
	l[a]=ll;
	r[a]=rr;
	lz[a]=1;
	if(ll==rr)
		return;
	int mid=(ll+rr)>>1;
	build(a<<1,ll,mid);
	build(a<<1|1,mid+1,rr);
}
void down(int a)
{
	if(lz[a]==1)
		return;
	int la=a<<1,ra=a<<1|1,t=lz[a];
	sm[la]=(li)sm[la]*t%mod;
	sm[ra]=(li)sm[ra]*t%mod;
	lz[la]=(li)lz[la]*t%mod;
	lz[ra]=(li)lz[ra]*t%mod;
	lz[a]=1;
}
void mul(int a,int ll,int rr,int val)
{
	if(l[a]>rr||r[a]<ll)
		return;
	if(l[a]>=ll&&r[a]<=rr)
	{
		sm[a]=(li)sm[a]*val%mod;
		lz[a]=(li)lz[a]*val%mod;
		return;
	}
	down(a);
	mul(a<<1,ll,rr,val);
	mul(a<<1|1,ll,rr,val);
	sm[a]=(sm[a<<1]+sm[a<<1|1])%mod;
}
void add(int a,int pos,int val)
{
	if(l[a]==r[a])
	{
		sm[a]=(sm[a]+val)%mod;
		return;
	}
	down(a);
	if(pos<=r[a<<1])
		add(a<<1,pos,val);
	else
		add(a<<1|1,pos,val);
	sm[a]=(sm[a<<1]+sm[a<<1|1])%mod;
}
int ask(int a,int ll,int rr)
{
	if(l[a]>rr||r[a]<ll)
		return 0;
	if(l[a]>=ll&&r[a]<=rr)
		return sm[a];
	down(a);
	return (ask(a<<1,ll,rr)+ask(a<<1|1,ll,rr))%mod;
}
void dfs(int x)
{
	ed[x]=dfn[x]=++tme;
	for(int i=hd[x];i;i=nxt[i])
	{
		dfs(eg[i]);
		ed[x]=max(ed[x],ed[eg[i]]);
	}
}
void solve()
{
	build(1,1,n);
	for(int i=1;i<=n;i++)
		cp[i]=1;
	add(1,dfn[1],v[1]);
	deg[1]=1;
	for(int i=1;i<=smq;i++)
	{
		if(q[i].fi==0)
		{
			int x=q[i].se;
			int val=ask(1,dfn[x],ed[x]);
			int bs=f[x]?askc(dfn[f[x]]):1;
			// printf("val:%d bs:%d\n",val,bs);
			int ans=(li)val*qpow(bs,mod-2)%mod;
			printf("%d\n",ans);
		}
		else
		{
			int fa=q[i].fi,x=q[i].se;
			int dg=deg[fa];
			deg[fa]++,deg[x]++;
			int val=(qpow(dg,mod-2)+1)%mod;
			mul(1,dfn[fa],ed[fa],val);
			addc(ed[fa],val);
			addc(dfn[fa]-1,qpow(val,mod-2));
			add(1,dfn[x],(li)v[x]*askc(dfn[x])%mod);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif
	scanf("%d%d",v+1,&m);
	for(int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==1)
		{
			scanf("%d",&c);
			v[++n]=c;
			q[++smq]=pii(b,n);
			ins(b,n);
			f[n]=b;
		}
		else
			q[++smq]=pii(0,b);
	}
	dfs(1);
	solve();
	return 0;
}