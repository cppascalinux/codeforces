//2019.05.28
//CF702F T-Shirts 将衣服,顾客分别排序,每次对顾客序列进行操作,[0,c)的不变,[c,2c)的暴力-c,[2c,inf]的打标记
//用splay维护,打标记,每个元素暴力后至少/2,最多暴力log次,时间复杂度O(nlog^2n)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
#define inf 0x7F7F7F7F
using namespace std;
int n,m,cnt,rt;
pii s[200009],pp[200009];
int ans[200009];
int f[200009],ch[200009][2],sz[200009],v[200009],lz[200009];
bool cmp1(pii a,pii b)
{
	return a.se==b.se?a.fi<b.fi:a.se>b.se;
}
int build(int l,int r)
{
	if(l>r)
		return 0;
	int mid=(l+r)>>1;
	int x=pp[mid].se;
	v[x]=pp[mid].fi;
	ch[x][0]=build(l,mid-1);
	ch[x][1]=build(mid+1,r);
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	return x;
}
void down(int x)
{
	if(!lz[x])
		return;
	int lx=ch[x][0],rx=ch[x][1],t=lz[x];
	v[lx]-=t,v[rx]-=t;
	lz[lx]+=t,lz[rx]+=t;
	ans[lx]+=t,ans[rx]+=t;
	lz[x]=0;
}
void update(int x)
{
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
void rotate(int x)
{
	int y=f[x],z=f[y],dx=x==ch[y][1],dy=y==ch[z][1];
	f[x]=z;
	f[y]=x;
	f[ch[x][dx^1]]=y;
	ch[z][dy]=x;
	ch[y][dx]=ch[x][dx^1];
	ch[x][dx^1]=y;
	update(y);
	update(x);
}
void splay(int x,int fa)
{
	while(f[x]!=fa)
	{
		int y=f[x],z=f[y];
		if(f[y]!=fa)
			rotate((x==ch[y][1])^(y==ch[z][1])?x:y);
		rotate(x);
	}
	if(!fa)
		rt=x;
}
void ins(int x,int fa,int id,int val)
{
	if(!x)
	{
		x=id;
		if(fa)
			ch[fa][val>=v[fa]]=x;
		f[x]=fa;
		sz[x]=1;
		lz[x]=0;
		v[x]=val;
		ch[x][0]=ch[x][1]=0;
		splay(x,0);
		return;
	}
	ins(ch[x][val>=v[x]],x,id,val);
}
int rnk(int x,int val)
{
	if(!x)
		return 1;
	if(val>=v[x])
		return sz[ch[x][0]]+1+rnk(ch[x][1],val);
	return rnk(ch[x][0],val);
}
int kth(int x,int k)
{
	if(k==sz[ch[x][0]]+1)
		return splay(x),x;
	if(k<=sz[ch[x][0]])
		return kth(ch[x][0],k);
	return kth(ch[x][1],k-sz[ch[x][0]]-1);
}
void solve()
{
	sort(s+1,s+n+1,cmp1);
	sort(pp+1,pp+m+1);
	rt=build(1,m);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("tshirts.in","r",stdin);
	freopen("tshirts.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&s[i].fi,&s[i].se);//price,quality
	scanf("%d",&m);
	for(int i=1,a;i<=m;i++)
	{
		scanf("%d",&a);
		ins(rt,0,i,a);
	}
	ins(rt,0,m+1,-inf);
	ins(rt,0,m+2,inf);
	solve();
	return 0;
}