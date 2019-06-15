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
int n,m,rt;
pii s[200009];
int f[200009],ch[200009][2],ccf[200009],sm[200009],sz[200009],lzccf[200009],lzsm[200009];
int st[200009];
int tmpid[200009],tmpv1[200009],tmpv2[200009];
void update(int x)
{
	if(x)
		sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
void down(int x)
{
	int lx=ch[x][0],rx=ch[x][1],v1=lzccf[x],v2=lzsm[x];
	if(lx)
	{
		lzccf[lx]+=v1,lzsm[lx]+=v2;
		if(lx<=m)
			ccf[lx]+=v1,sm[lx]+=v2;
	}
	if(rx)
	{
		lzccf[rx]+=v1,lzsm[rx]+=v2;
		if(rx<=m)
			ccf[rx]+=v1,sm[rx]+=v2;
	}
	lzsm[x]=lzccf[x]=0;
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
	int y,z,tp=0;
	for(y=x;y!=fa;y=f[y])
		st[++tp]=y;
	for(;tp>=1;tp--)
		down(st[tp]);
	while(f[x]!=fa)
	{
		y=f[x],z=f[y];
		if(z!=fa)
			rotate((x==ch[y][1])!=(y==ch[z][1])?x:y);
		rotate(x);
	}
	if(!fa)
		rt=x;
}
void ins(int x,int fa,int id,int v1,int v2)
{
	if(!x)
	{
		f[id]=fa;
		ch[id][0]=ch[id][1]=0;
		sz[id]=1;
		ccf[id]=v1,sm[id]=v2;
		lzccf[id]=lzsm[id]=0;
		if(fa)
			ch[fa][v1>ccf[fa]]=id;
		splay(id,0);
		return;
	}
	down(x);
	ins(ch[x][v1>ccf[x]],x,id,v1,v2);
}
int rnk(int p,int val)
{
	if(!p)
		return 1;
	down(p);
	if(val<=ccf[p])
		return rnk(ch[p][0],val);
	return rnk(ch[p][1],val)+sz[ch[p][0]]+1;
}
int kth(int p,int k)
{
	if(k==sz[ch[p][0]]+1)
		return splay(p,0),p;
	down(p);
	if(k<=sz[ch[p][0]])
		return kth(ch[p][0],k);
	return kth(ch[p][1],k-sz[ch[p][0]]-1);
}
void dfs(int x,int &tp)
{
	if(!x)
		return;
	down(x);
	dfs(ch[x][0],tp);
	tmpid[++tp]=x;
	tmpv1[tp]=ccf[x];
	tmpv2[tp]=sm[x];
	dfs(ch[x][1],tp);
}
bool cmp(pii a,pii b)
{
	return a.se==b.se?a.fi<b.fi:a.se>b.se;
}
void solve()
{
	sort(s+1,s+n+1,cmp);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d fi:%d se:%d\n",i,s[i].fi,s[i].se);
	for(int i=1;i<=n;i++)
	{
		int v=s[i].fi;
		int pa=kth(rt,rnk(rt,v)-1),pb=kth(rt,rnk(rt,2*v));
		// printf("i:%d v:%d pa:%d pb:%d\n",i,v,pa,pb);
		// printf("1:%d 2:%d 3:%d 4:%d\n",kth(rt,1),kth(rt,2),kth(rt,3),kth(rt,4));
		// printf("rnk3:%d\n",rnk(rt,3));
		splay(pa,0),splay(pb,pa);
		sm[pb]++,lzsm[pb]++;
		down(pa),down(pb);
		int tp=0;
		dfs(ch[pb][0],tp);
		ch[pb][0]=0;
		update(pb),update(pa);
		lzccf[pb]-=v;
		if(pb<=m)
			ccf[pb]-=v;
		for(int i=1;i<=tp;i++)
			ins(rt,0,tmpid[i],tmpv1[i]-v,tmpv2[i]);
		// tp=0;
		// dfs(rt,tp);
		// for(int i=1;i<=tp;i++)
		// 	printf("id:%d ccf:%d sm:%d\n",tmpid[i],tmpv1[i],tmpv2[i]);
	}
	int tp=0;
	dfs(rt,tp);
	for(int i=1;i<=m;i++)
		printf("%d ",sm[i]);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("tshirts.in","r",stdin);
	freopen("tshirts.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&s[i].fi,&s[i].se);
	scanf("%d",&m);
	for(int i=1,a;i<=m;i++)
	{
		scanf("%d",&a);
		ins(rt,0,i,a,0);
	}
	ins(rt,0,m+1,-inf,0);
	ins(rt,0,m+2,inf,0);
	solve();
	return 0;
}