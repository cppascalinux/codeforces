//2019.05.18
//CF603D 利用答案的单调性按时间分治
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define inf 0x7F7F7F7F
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
int n,m;
int f[100009],sz[100009];
int ans[300009];
edge e[300009],pe[300009];
pii bf[29][100009],bsz[29][100009];
int tp[29];
int fnd(int x)
{
	return x==f[x]?x:fnd(f[x]);
}
void rd(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch&15),ch=gc();
}
int uni(int d,int a,int b)
{
	a=fnd(a),b=fnd(b);
	if(a==b)
		return 0;
	int ret=0;
	if((sz[a]&1)&&(sz[b]&1))
		ret=2;
	if(sz[a]>sz[b])
		swap(a,b);
	bf[d][++tp[d]]=pii(a,f[a]);
	f[a]=b;
	bsz[d][tp[d]]=pii(b,sz[b]);
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
	assert(tp[d]==0);
}
void solve(int d,int sm,int l,int r,int lo,int hi)
{
	if(l>r)
		return;
	if(lo>hi)
	{
		for(int i=l;i<=r;i++)
			ans[i]=-1;
		return;
	}
	int ansm=hi+1,mid=(l+r)>>1,tsm=sm;
	for(int i=l;i<=mid;i++)
		if(e[i].id<lo)
			tsm-=uni(d,e[i].u,e[i].v);
	for(int i=lo;i<=hi;i++)
		if(pe[i].id<=mid)
			if(!(tsm-=uni(d,pe[i].u,pe[i].v)))
			{
				ansm=i;
				break;
			}
	ans[mid]=ansm>hi?-1:pe[ansm].l;
	roll(d),tsm=sm;
	for(int i=lo;i<=ansm-1;i++)
		if(pe[i].id<l)
			tsm-=uni(d,pe[i].u,pe[i].v);
	solve(d+1,tsm,l,mid-1,ansm,hi);
	roll(d),tsm=sm;
	for(int i=l;i<=mid;i++)
		if(e[i].id<lo)
			tsm-=uni(d,e[i].u,e[i].v);
	solve(d+1,tsm,mid+1,r,lo,ansm);
	roll(d),tsm=sm;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("lct.in","r",stdin);
	freopen("dc.out","w",stdout);
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
		pe[i]=e[i]=edge(a,b,c,i);
	}
	sort(pe+1,pe+m+1);
	for(int i=1;i<=m;i++)
		e[pe[i].id].id=i;
	solve(1,n,1,m,1,m);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}