//2019.05.18
//CF603E Pastoral Oddities LCT维护最小生成树+维护黑白边+并查集维护联通块大小
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define gc() (p1==p2&&(p2=(p1=buffer)+fread(buffer,1,10000000,stdin),p1==p2)?EOF:*p1++)
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
#define nrt(x) x==lc(f[x])||x==rc(f[x])
#define cmp(x,y) (mx[x]>mx[y]||(mx[x]==mx[y]&&mi[x]>mi[y]))
#define inf 0x7F7F7F7F
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
int f[500009],ch[500009][2],rv[500009],val[500009],mx[500009],mi[500009];//lct
int cl[500009],lz[500009],st[500009];//lct
edge e[400009];
void rd(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch&15),ch=gc();
}
void update(int x)
{
	mx[x]=val[x],mi[x]=x;
	int lx=lc(x),rx=rc(x);
	if(cmp(lx,x))
		mx[x]=mx[lx],mi[x]=mi[lx];
	if(cmp(rx,x))
		mx[x]=mx[rx],mi[x]=mi[rx];
}
void down(int x)
{
	int &lx=lc(x),&rx=rc(x);
	if(rv[x])
		swap(lx,rx),rv[x]=0,rv[lx]^=1,rv[rx]^=1;
	if(lz[x])
		lz[x]=0,cl[lx]^=1,lz[lx]^=1,cl[rx]^=1,lz[rx]^=1;
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
		rc(x)=y;
		update(x);
	}
}
void makert(int x)
{
	access(x);
	splay(x);
	rv[x]^=1;
}
void split(int x,int y)
{
	makert(x);
	access(y);
	splay(x);
}
void lnk(int x,int y)
{
	makert(y);
	f[y]=x;
}
void cut(int x,int y)
{
	split(x,y);
	rc(x)=f[y]=0;
	update(x);
}
void solve()
{
	set<edge> s;
	set<edge>::iterator it;
	for(int i=m+1;i<=m+n-1;i++)
		s.insert(e[i]);
	// for(it=s.begin();it!=s.end();it++)
	// 	splay(it->id),printf("u:%d v:%d l:%d id:%d cl:%d\n",it->u,it->v,it->l,it->id-n,cl[it->id]);
	edge lans=e[m+n-1];
	for(int i=1;i<=m;i++)
	{
		int x=e[i].u,y=e[i].v,ln=e[i].l;
		split(x,y);
		// printf("x:%d y:%d mi:%d\n",x,y,mi[x]);
		if(ln!=mx[x]?ln<mx[x]:i+n<mi[x])
		{
			int p=mi[x]-n;
			splay(p+n);
			int nc=cl[p+n];
			// printf("p:%d nc:%d\n",p,nc);
			cut(p+n,e[p].u);
			cut(p+n,e[p].v);
			s.erase(e[p]);
			lnk(i+n,x);
			lnk(i+n,y);
			s.insert(e[i]);
			if(nc)
			{
				split(e[p].u,e[p].v);
				cl[e[p].u]^=1,lz[e[p].u]^=1;
			}
			it=s.upper_bound(lans),it--;
			while(splay(it->id),cl[it->id]==0)
				it--;
			lans=*it;
		}
		if(lans.l==inf)
			printf("-1\n");
		else
			printf("%d\n",lans.l);
		// if(i>=9)
			// splay(lans.id);
			// printf("llans!! u:%d v:%d l:%d id:%d cl:%d\n",lans.u,lans.v,lans.l,lans.id,cl[lans.id]);
			// for(it=s.begin();it!=s.end();it++)
			// 	splay(it->id),printf("u:%d v:%d l:%d id:%d cl:%d\n",it->u,it->v,it->l,it->id-n,cl[it->id]);
	}
}
void init()
{
	for(int i=1;i<=n-1;i++)
	{
		e[i+m]=edge(i,i+1,inf,i+m+n);
		cl[i+m+n]=i&1;
		val[i+m+n]=mx[i+m+n]=inf;
		mi[i+m+n]=i+m+n;
		lnk(i+m+n,i);
		lnk(i+m+n,i+1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("lct.in","r",stdin);
	freopen("lct1.out","w",stdout);
#endif
	rd(n),rd(m);
	if(n&1)
	{
		for(int i=1;i<=m;i++)
			printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		mi[i]=i;
	for(int i=1,a,b,c;i<=m;i++)
	{
		rd(a),rd(b),rd(c);
		e[i]=edge(a,b,c,i+n);
		val[i+n]=mx[i+n]=c;
		mi[i+n]=i+n;
	}
	init();
	solve();
	return 0;
}