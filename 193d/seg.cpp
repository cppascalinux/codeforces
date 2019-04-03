//cf193d two segments 线段树维护dp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
#define pii pair<int,int>
#define fi first
#define se second
#define long long long
using namespace std;
struct node
{
	int v1,sm1,v2,sm2;
	node(){}
	node(int a,int b,int c,int d){v1=a,sm1=b,v2=c,sm2=d;}
};
int n;
long ans;
int id[300009],pos[300009];
int l[1200009],r[1200009],lz[1200009];
node p[1200009];
node mrg(node a,node b)
{
	int tp=0,cnt=0;
	pii tmp[5];
	tmp[++tp]=pii(a.v1,a.sm1);
	if(a.v2<inf)
		tmp[++tp]=pii(a.v2,a.sm2);
	tmp[++tp]=pii(b.v1,b.sm1);
	if(b.v2<inf)
		tmp[++tp]=pii(b.v2,b.sm2);
	sort(tmp+1,tmp+tp+1);
	pii oth[5];
	for(int i=1;i<=4;i++)
		oth[i]=pii(inf,0);
	for(int i=1;i<=tp;i++)
		if(tmp[i].fi==tmp[i-1].fi)
			oth[cnt].se+=tmp[i].se;
		else
			oth[++cnt]=tmp[i];
	return node(oth[1].fi,oth[1].se,oth[2].fi,oth[2].se);
}
void down(int a)
{
	if(!lz[a])
		return;
	int la=a<<1,ra=a<<1|1,t=lz[a];
	p[la].v1+=t;
	if(p[la].v2)
		p[la].v2+=t;
	p[ra].v1+=t;
	if(p[ra].v2)
		p[ra].v2+=t;
	lz[la]+=t;
	lz[ra]+=t;
	lz[a]=0;
}
void build(int a,int ll,int rr)
{
	l[a]=ll;
	r[a]=rr;
	if(ll==rr)
	{
		p[a]=node(inf,1,inf,1);
		return;
	}
	int mid=(ll+rr)>>1;
	build(a<<1,ll,mid);
	build(a<<1|1,mid+1,rr);
	p[a]=mrg(p[a<<1],p[a<<1|1]);
}
void add(int a,int ll,int rr,int val)
{
	if(l[a]>rr||r[a]<ll)
		return;
	if(l[a]>=ll&&r[a]<=rr)
	{
		lz[a]+=val;
		p[a].v1+=val;
		if(p[a].v2<inf)
			p[a].v2+=val;
		return;
	}
	down(a);
	add(a<<1,ll,rr,val);
	add(a<<1|1,ll,rr,val);
	p[a]=mrg(p[a<<1],p[a<<1|1]);
}
void solve(int x)
{
	add(1,x,x,1-inf);
	int g=pos[x];
	int p1=id[g-1],p2=id[g+1];
	int sm=(p1>x)+(p2>x);
	if(p1>p2)
		swap(p1,p2);
	if(!sm)
		add(1,x+1,n,1);
	else if(sm==1)
		add(1,x+1,p2-1,1);
	else
	{
		add(1,x+1,p1-1,1);
		add(1,p2,n,-1);
	}
	if(p[1].v1==1)
		ans+=p[1].sm1;
	if(p[1].v2==2)
		ans+=p[1].sm2;
	// printf("x:%d p1:%d p2:%d sm:%d v1:%d v2:%d sm1:%d sm2:%d\n",x,p1,p2,sm,p[1].v1,p[1].v2,p[1].sm1,p[1].sm2);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("seg.in","r",stdin);
	freopen("seg.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",id+i);
		pos[id[i]]=i;
	}
	build(1,1,n);
	// printf("v1:%d v2:%d sm1:%d sm2:%d\n",p[1].v1,p[1].v2,p[1].sm1,p[1].sm2);
	for(int i=n;i>=1;i--)
		solve(i);
	printf("%lld",ans-n);
	return 0;
}