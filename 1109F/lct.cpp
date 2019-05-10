//2019.05.10
//CF1109F Sasha and Algorithm of Silence's Sounds 区间单调性+LCT+线段树
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
#define nrt(x) x==rc(f[x])||x==lc(f[x])
#define inf 0x7F7F7F7F
#define pii pair<int,int>
#define fi first
#define se second
#define li long long
using namespace std;
int n,m;
int mat[1009][1009];
int f[200009],ch[200009][2],rv[200009],st[200009];
int l[800009],r[800009],mn[800009],sm[800009],lz[800009];
pii pos[200009];
int dk[5][2]={{},{1,0},{-1,0},{0,1},{0,-1}};
void rot(int x)
{
	int y=f[x],z=f[y],dx=x==rc(y),dy=y==rc(z);
	if(nrt(y))
		ch[z][dy]=x;
	f[x]=z;
	f[y]=x;
	f[ch[x][dx^1]]=y;
	ch[y][dx]=ch[x][dx^1];
	ch[x][dx^1]=y;
}
void down(int x)
{
	if(rv[x])
		swap(lc(x),rc(x)),rv[lc(x)]^=1,rv[rc(x)]^=1,rv[x]=0;
}
void splay(int x)
{
	int y,z,tp=0;
	for(y=x;nrt(y);y=f[y])
		st[++tp]=y;
	st[++tp]=y;
	for(int i=tp;i>=1;i--)
		down(st[i]);
	while(nrt(x))
	{
		y=f[x],z=f[y];
		if(nrt(y))
			rot((x==rc(y))^(y==rc(z))?x:y);
		rot(x);
	}
}
void access(int x)
{
	for(int y=0;x;y=x,x=f[x])
	{
		splay(x);
		rc(x)=y;
	}
}
int findrt(int x)
{
	access(x);
	splay(x);
	down(x);
	while(lc(x))
		down(x=lc(x));
	splay(x);
	return x;
}
void makert(int x)
{
	access(x);
	splay(x);
	rv[x]^=1;
}
int lnk(int x,int y)
{
	makert(y);
	if(findrt(x)==y)
		return 0;
	f[y]=x;
	return 1;
}
int cut(int x,int y)
{
	makert(x);
	if(findrt(y)==x&&f[y]==x&&!lc(y))
	{
		f[y]=rc(x)=0;
		return 1;
	}
	return 0;
}
int judge(int x,int y)
{
	return findrt(x)==findrt(y);
}
void downs(int a)
{
	if(!lz[a])
		return;
	int la=a<<1,ra=a<<1|1,t=lz[a];
	mn[la]+=t,mn[ra]+=t;
	lz[la]+=t,lz[ra]+=t;
	lz[a]=0;
}
void upd(int a)
{
	int la=a<<1,ra=a<<1|1;
	if(mn[la]==mn[ra])
		mn[a]=mn[la],sm[a]=sm[la]+sm[ra];
	else
	{
		mn[a]=min(mn[la],mn[ra]);
		sm[a]=mn[la]<mn[ra]?sm[la]:sm[ra];
	}
}
void build(int a,int ll,int rr)
{
	l[a]=ll;
	r[a]=rr;
	mn[a]=inf;
	sm[a]=1;
	if(ll<rr)
	{
		int mid=(ll+rr)>>1;
		build(a<<1,ll,mid);
		build(a<<1|1,mid+1,rr);
		upd(a);
	}
}
void add(int a,int ll,int rr,int val)
{
	if(l[a]>rr||r[a]<ll)
		return;
	if(l[a]>=ll&&r[a]<=rr)
	{
		mn[a]+=val;
		lz[a]+=val;
		return;
	}
	downs(a);
	add(a<<1,ll,rr,val);
	add(a<<1|1,ll,rr,val);
	upd(a);
}
int ask(int a,int ll,int rr)
{
	if(l[a]>rr||r[a]<ll)
		return 0;
	if(l[a]>=ll&&r[a]<=rr)
	{
		if(mn[a]!=1)
			return 0;
		return sm[a];
	}
	downs(a);
	return ask(a<<1,ll,rr)+ask(a<<1|1,ll,rr);
}
int test(int lp,int rp)
{
	int px=pos[lp].fi,py=pos[lp].se;
	int tmp[5],tp=0;
	for(int i=1;i<=4;i++)
	{
		int np=mat[px+dk[i][0]][py+dk[i][1]];
		if(np>=lp&&np<=rp)
			tmp[++tp]=np;
	}
	for(int i=1;i<=tp-1;i++)
	{
		makert(tmp[i]);
		for(int j=i+1;j<=tp;j++)
			if(findrt(tmp[j])==tmp[i])
				return 0;
	}
	return 1;
}
void solve()
{
	build(1,1,n*m);
	// for(int i=1;i<=n*m;i++)
	// 	printf("l:%d r:%d mn:%d sm:%d\n",l[i],r[i],mn[i],sm[i]);
	int rp=n*m;
	li ans=0;
	for(int lp=n*m;lp>=1;lp--)
	{
		while(!test(lp,rp))
		{
			int rx=pos[rp].fi,ry=pos[rp].se;
			for(int i=1;i<=4;i++)
			{
				int np=mat[rx+dk[i][0]][ry+dk[i][1]];
				if(np>=lp&&np<=rp)
					cut(rp,np);
			}
			rp--;
		}
		// printf("lp:%d rp:%d\n",lp,rp);
		int lx=pos[lp].fi,ly=pos[lp].se;
		for(int i=1;i<=4;i++)
		{
			int np=mat[lx+dk[i][0]][ly+dk[i][1]];
			if(np>=lp&&np<=rp)
				lnk(lp,np);
		}
		add(1,lp,lp,-inf);
		add(1,lp,rp,1);
		for(int i=1;i<=4;i++)
		{
			int np=mat[lx+dk[i][0]][ly+dk[i][1]];
			if(np>=lp&&np<=rp)
				add(1,np,rp,-1);
		}
		ans+=ask(1,lp,rp);
	}
	printf("%lld",ans);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("lct.in","r",stdin);
	freopen("lct.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",mat[i]+j);
			pos[mat[i][j]]=pii(i,j);
		}
	solve();
	return 0;
}