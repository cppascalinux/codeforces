//cf809d Hitchhiking in the Baltic States dp+splay
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
#define upd(x) sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1
using namespace std;
int n,rt,cnt;
int pool[300009],st[300009];
int ch[300009][2],f[300009],v[300009],sz[300009],lz[300009];
int tmp[300009],tp;
int dn[300009];
void down(int x)
{
	int lx=ch[x][0],rx=ch[x][1];
	if(lx)
	{
		lz[lx]+=lz[x];
		v[lx]+=lz[x];
	}
	if(rx)
	{
		lz[rx]+=lz[x];
		v[rx]+=lz[x];
	}
	lz[x]=0;
}
void rotate(int x)
{
	int y=f[x],z=f[y];
	int dx=x==ch[y][1],dy=y==ch[z][1];
	f[x]=z;
	f[y]=x;
	f[ch[x][dx^1]]=y;
	ch[z][dy]=x;
	ch[y][dx]=ch[x][dx^1];
	ch[x][dx^1]=y;
	upd(y);
	upd(x);
}
void splay(int x,int fa)
{
	while(f[x]!=fa)
	{
		int y=f[x],z=f[y];
		if(z!=fa)
			rotate((x==ch[y][1])^(y==ch[z][1])?x:y);
		rotate(x);
	}
	if(!fa)
		rt=x;
}
int kth(int x,int k)
{
	down(x);
	int lsm=sz[ch[x][0]];
	if(k==lsm+1)
	{
		splay(x,0);
		return x;
	}
	if(k<=lsm)
		return kth(ch[x][0],k);
	return kth(ch[x][1],k-lsm-1);
}
int rnk(int x,int val)
{
	down(x);
	if(!x)
		return 1;
	if(val<=v[x])
		return rnk(ch[x][0],val);
	return rnk(ch[x][1],val)+sz[ch[x][0]]+1;
}
void ins(int k,int val)
{
	int pl=kth(rt,k-1),pr=kth(rt,k);
	splay(pl,0);
	splay(pr,pl);
	int p=pool[cnt--];
	ch[p][0]=ch[p][1]=0;
	v[p]=val;
	sz[p]=1;
	lz[p]=0;
	f[p]=pr;
	ch[pr][0]=p;
	upd(pr);
	upd(pl);
}
void del(int k)
{
	int pl=kth(rt,k-1),pr=kth(rt,k+1);
	splay(pl,0);
	splay(pr,pl);
	int p=ch[pr][0];
	pool[++cnt]=p;
	ch[pr][0]=0;
	upd(pr);
	upd(pl);
}
void add(int l,int r)
{
	if(l>r)
		return;
	int pl=kth(rt,l-1),pr=kth(rt,r+1);
	splay(pl,0);
	splay(pr,pl);
	int p=ch[pr][0];
	v[p]++;
	lz[p]++;
}
void build(int &p,int fa,int l,int r)
{
	if(l>r)
		return;
	p=pool[cnt--];
	int mid=(l+r)>>1;
	v[p]=st[mid];
	sz[p]=1;
	lz[p]=0;
	ch[p][0]=ch[p][1]=0;
	f[p]=fa;
	build(ch[p][0],p,l,mid-1);
	build(ch[p][1],p,mid+1,r);
	upd(p);
}
void init()
{
	for(int i=1;i<=n+5;i++)
		pool[i]=i;
	cnt=n+5;
	st[1]=0;
	for(int i=2;i<=n+2;i++)
		st[i]=inf;
	build(rt,0,1,n+2);
}
void solve(int lval,int rval)
{
	int lk=rnk(rt,lval),rk=rnk(rt,rval);
	// printf("lval:%d lk:%d rval:%d rk:%d\n",lval,lk,rval,rk);
	del(rk);
	ins(lk,lval);
	add(lk+1,rk);
}
void dfs(int x)
{
	if(!x)
		return;
	down(x);
	dfs(ch[x][0]);
	// printf("x:%d v:%d sz:%d lz:%d f:%d\n",x,v[x],sz[x],lz[x],f[x]);
	tmp[++tp]=v[x];
	dfs(ch[x][1]);
}
void dbg()
{
	tp=0;
	dfs(rt);
	for(int i=1;i<=n+1;i++)
		printf("%d ",tmp[i]);
	printf("\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
#endif
	scanf("%d",&n);
	init();
	// dbg();
	for(int i=1,l,r;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		solve(l,r);
		// dbg();
		// printf("\n");
	}
	int ans=rnk(rt,inf)-2;
	printf("%d",ans);
	return 0;
}