#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define inf 0x7F7F7F7F
using namespace std;
int n,m,tot;
pii p[100009],q[100009];
struct seg
{
	pii l,r;
	bool operator<(const seg &p)const{return l<p.l;}
};
seg ans[200009];
bool cmp(pii a,pii b)
{
	return a.se<b.se||(a.se==b.se&&a.fi<b.fi);
}
void init()
{
	sort(p+1,p+n+1);
	sort(q+1,q+n+1,cmp);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d p:%d %d q:%d %d\n",i,p[i].fi,p[i].se,q[i].fi,q[i].se);
	pii cur(0,0);
	int lp=0,lq=0;
	while(lp<n||lq<n)
	{
		int dt=inf;
		if(lp<n)
			dt=min(dt,p[lp+1].fi-cur.fi);
		if(lq<n)
			dt=min(dt,q[lq+1].se-cur.se);
		int nx=cur.fi+dt,ny=cur.se+dt;
		// printf("lp:%d lq:%d dt:%d nx:%d ny:%d\n",lp,lq,dt,nx,ny);
		int fgx=0,fgy=0;;
		if(lp<n&&nx==p[lp+1].fi)
		{
			if(p[lp+1].se<=ny)
			{
				fgx=1;
				lp++;
				while(lp<n&&nx==p[lp+1].fi)
					lp++;
			}
		}
		if(lq<n&&ny==q[lq+1].se)
		{
			if(q[lq+1].fi<=nx)
			{
				fgy=1;
				while(lq<n&&ny==q[lq+1].se)
					lq++;
			}
		}
		if(!fgx&&!fgy)
		{
			while(lp<n&&nx==p[lp+1].fi)
				lp++;
			while(lq<n&&ny==q[lq+1].se)
				lq++;
			continue;
		}
		if(nx-1>=cur.fi)
			ans[++tot]=seg{cur,pii(nx-1,ny-1)};
		if(fgx)
			nx++;
		if(fgy)
			ny++;
		cur=pii(nx,ny);
	}
	int dt=inf-max(cur.fi,cur.se);
	ans[++tot]=seg{cur,pii(cur.fi+dt,cur.se+dt)};
	// for(int i=1;i<=tot;i++)
	// 	printf("i:%d lx:%d ly:%d rx:%d ry:%d\n",i,ans[i].l.fi,ans[i].l.se,ans[i].r.fi,ans[i].r.se);
}
int main()
{
	scanf("%d%d",&n,&m);
	set<pii> s;
	s.insert(pii(0,0));
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		s.insert(pii(a,b));
		p[i]=q[i]=pii(a,b);
	}
	n++;
	p[n]=q[n]=pii(0,0);
	init();
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		pii c(a,b);
		if(s.count(c))
		{
			printf("LOSE\n");
			continue;
		}
		seg t=*(upper_bound(ans+1,ans+tot+1,seg{c,pii(0,0)})-1);
		if(a-t.l.fi==b-t.l.se&&a>=t.l.fi&&a<=t.r.fi)
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}