//2019.05.19
//CF603E Pastoral Oddities 每条边被使用的时间是一段区间,使用线段树分治
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cassert>
#define gc() (p1==p2&&(p2=(p1=buffer)+fread(buffer,1,10000000,stdin),p1==p2)?EOF:*p1++)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
struct edge
{
	int u,v,l,id;
	edge(){}
	edge(int a,int b,int c,int d){u=a,v=b,l=c,id=d;}
	bool operator <(const edge &p) const{return l<p.l||(l==p.l&&id<p.id);}
};
char *p1,*p2,buffer[10000009];
int n,m,cur;
int l[1200009],r[1200009];
vector<int> v[1200009];
edge e[300009];
int ans[300009];
int f[100009],sz[100009];
pii bf[29][100009],bsz[29][100009];
int tp[29];
void rd(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch&15),ch=gc();
}
int fnd(int x)
{
	return x==f[x]?x:fnd(f[x]);
}
int uni(int d,int a,int b)
{
	a=fnd(a),b=fnd(b);
	if(a==b)
		return 0;
	if(sz[a]>sz[b])
		swap(a,b);
	int ret=0;
	if((sz[a]&1)&&(sz[b]&1))
		ret=2;
	bf[d][++tp[d]]=pii(a,f[a]);
	bsz[d][tp[d]]=pii(b,sz[b]);
	f[a]=b;
	sz[b]+=sz[a];
	return ret;
}
void roll(int d)
{
	for(int &i=tp[d];i>=1;i--)
	{
		pii tf=bf[d][i],tsz=bsz[d][i];
		f[tf.fi]=tf.se;
		sz[tsz.fi]=tsz.se;
	}
}
void build(int a,int ll,int rr)
{
	l[a]=ll;
	r[a]=rr;
	if(ll<rr)
	{
		int mid=(ll+rr)>>1;
		build(a<<1,ll,mid);
		build(a<<1|1,mid+1,rr);
	}
}
void add(int a,int ll,int rr,int val)
{
	if(ll>rr)
		return;
	if(l[a]>rr||r[a]<ll)
		return;
	if(l[a]>=ll&&r[a]<=rr)
	{
		v[a].push_back(val);
		return;
	}
	add(a<<1,ll,rr,val);
	add(a<<1|1,ll,rr,val);
}
void solve(int d,int sm,int a)
{
	int tsm=sm;
	for(int i=0;i<(int)v[a].size();i++)
	{
		int p=v[a][i];
		tsm-=uni(d,e[p].u,e[p].v);
	}
	if(l[a]!=r[a])
		solve(d+1,tsm,a<<1|1),solve(d+1,tsm,a<<1);
	else
	{
		while(cur<=m&&tsm)
		{
			cur++;
			if(e[cur].id>l[a])
				continue;
			else
			{
				tsm-=uni(d,e[cur].u,e[cur].v);
				add(1,e[cur].id,l[a]-1,cur);
			}
		}
		ans[l[a]]=cur>m?-1:e[cur].l;
	}
	roll(d);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("lct.in","r",stdin);
	freopen("dc1.out","w",stdout);
#endif
	rd(n),rd(m);
	if(n&1)
	{
		for(int i=1;i<=m;i++)
			printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
	for(int i=1,a,b,c;i<=m;i++)
	{
		rd(a),rd(b),rd(c);
		e[i]=edge(a,b,c,i);
	}
	sort(e+1,e+m+1);
	build(1,1,m);
	solve(1,n,1);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}