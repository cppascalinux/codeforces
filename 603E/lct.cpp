//2019.05.15
//CF603E Pastoral Oddities LCT维护最小生成树+LCT维护子树信息
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cassert>
#define gc() (p1==p2&&(p2=(p1=buffer)+fread(buffer,1,10000000,stdin),p1==p2)?EOF:*p1++)
#define inf 0x7F7F7F7F
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
#define nrt(x) x==lc(f[x])||x==rc(f[x])
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
int f[400009],ch[400009][2],rv[400009],sz[400009],si[400009],s0[400009];
int val[400009],mx[400009],mi[400009],st[400009];
edge e[300009];
void rd(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch&15),ch=gc();
}
void down(int x)
{
	if(rv[x])
		rv[x]=0,swap(lc(x),rc(x)),rv[lc(x)]^=1,rv[rc(x)]^=1;
}
void update(int x)
{
	sz[x]=sz[lc(x)]+sz[rc(x)]+si[x]+s0[x];
	mx[x]=val[x],mi[x]=x;
	if(mx[lc(x)]>mx[x])
		mx[x]=mx[lc(x)],mi[x]=mi[lc(x)];
	if(mx[rc(x)]>mx[x])
		mx[x]=mx[rc(x)],mi[x]=mi[rc(x)];
}
void rotate(int x)
{
	int y=f[x],z=f[y],dx=x==rc(y),dy=y==rc(z);
	if(nrt(y))
		ch[z][dy]=x;
	f[x]=z;
	f[y]=x;
	f[ch[x][dx^1]]=y;
	ch[y][dx]=ch[x][dx^1];
	ch[x][dx^1]=y;
	update(y);
	update(x);
}
void splay(int x)
{
	int tp=0,y,z;
	for(y=x;nrt(y);y=f[y])
		st[++tp]=y;
	st[++tp]=y;
	for(int i=tp;i>=1;i--)
		down(st[i]);
	while(nrt(x))
	{
		y=f[x],z=f[y];
		if(nrt(y))
			rotate((x==rc(y))^(y==rc(z))?x:y);
		rotate(x);
	}
}
void access(int x)
{
	for(int y=0;x;y=x,x=f[x])
	{
		splay(x);
		si[x]+=sz[rc(x)];
		si[x]-=sz[rc(x)=y];
		update(x);
	}
}
void makert(int x)
{
	access(x);
	splay(x);
	rv[x]^=1;
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
int ask(int x,int y)
{
	return makert(x),findrt(y)==x;
}
int lnk(int x,int y)
{
	makert(x);
	if(findrt(y)==x)
	{
		printf("wa1");
		assert(0);
		return 0;
	}
	makert(y);
	f[y]=x;
	si[x]+=sz[y];
	update(x);
	return 1;
}
int cut(int x,int y)
{
	makert(x);
	if(findrt(y)==x&&rc(x)==y&&lc(y)==0)
	{
		f[y]=rc(x)=0;
		update(x);
		return 1;
	}
	printf("wa2");
	assert(0);
	return 0;
}
void solve()
{
	int sm=n;
	set<edge> s;
	set<edge>::iterator it;
	for(int i=1;i<=m;i++)
	{
		int x=e[i].u,y=e[i].v,ln=e[i].l;
		// assert(!ask(x,y));
		if(!ask(x,y))
		{
			makert(x),makert(y);
			if((sz[x]&1)&&(sz[y]&1))
				sm-=2;
			lnk(i+n,x),lnk(i+n,y);
			s.insert(e[i]);
		}
		else if(mx[x]>ln)
		{
			int p=mi[x]-n;
			cut(p+n,e[p].u),cut(p+n,e[p].v);
			s.erase(e[p]);
			lnk(i+n,x),lnk(i+n,y);
			s.insert(e[i]);
		}
		// printf("i:%d\n",i),fflush(stdout);
		assert(!s.empty());
		if(!sm)
		{
			it=s.end();
			while(it!=s.begin())
			{
				it--;
				// printf("ok1\n"),fflush(stdout);
				int p=it->id-n;
				// printf("ok2 p:%d\n",p),fflush(stdout);
				makert(p+n);
				// printf("ok3\n"),fflush(stdout);
				access(e[p].u);
				// printf("ok4\n"),fflush(stdout);
				splay(p+n);
				// printf("ok5\n"),fflush(stdout);
				if(!((sz[p+n]-sz[e[p].u])&1)&&!(sz[e[p].u]&1))
					cut(p+n,e[p].u),cut(p+n,e[p].v);
				else
					break;
			}
			assert(it!=s.end());
			if(it!=s.end())
				s.erase(++it,s.end());
		}
		if(!sm)
		{
			it=s.end(),it--;
			printf("%d\n",it->l);
		}
		else
			printf("-1\n");
	}
	// for(it=s.begin();it!=s.end();it++)
	// 	printf("id:%d u:%d v:%d\n",it->id-n,it->u,it->v);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("lct.in","r",stdin);
	freopen("lct.out","w",stdout);
#endif
	rd(n),rd(m);
	if(n&1)
	{
		for(int i=1;i<=m;i++)
			printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		s0[i]=sz[i]=1,mi[i]=i;
	for(int i=1,a,b,c;i<=m;i++)
	{
		rd(a),rd(b),rd(c);
		e[i]=edge(a,b,c,i+n);
		val[i+n]=mx[i+n]=c;
		mi[i+n]=i+n;
	}
	solve();
	return 0;
}