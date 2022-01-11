#include<bits/stdc++.h>
#define inf 0x3F3F3F3F
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,d;
vector<pii> q[300009];
int lz[2400009],id[2400009];
int vs[600009];
int f[300009],pr[300009];
void dn(int a)
{
	int la=a*2,ra=a*2+1,&v=lz[a];
	if(!v)
		return;
	if(f[v]>f[id[la]])
		id[la]=v;
	if(f[v]>f[lz[la]])
		lz[la]=v;
	if(f[v]>f[id[ra]])
		id[ra]=v;
	if(f[v]>f[lz[ra]])
		lz[ra]=v;
	v=0;
}
void upd(int a)
{
	int la=a*2,ra=a*2+1;
	if(f[id[la]]>f[id[ra]])
		id[a]=id[la];
	else
		id[a]=id[ra];
}
void setmx(int a,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
	{
		if(f[v]>f[id[a]])
			id[a]=v;
		if(f[v]>f[lz[a]])
			lz[a]=v;
		return;
	}
	dn(a);
	int mid=(l+r)/2;
	setmx(a*2,l,mid,ll,rr,v);
	setmx(a*2+1,mid+1,r,ll,rr,v);
	upd(a);
}
int askmx(int a,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)
		return 0;
	if(l>=ll&&r<=rr)
		return id[a];
	dn(a);
	int mid=(l+r)/2;
	int ls=askmx(a*2,l,mid,ll,rr);
	int rs=askmx(a*2+1,mid+1,r,ll,rr);
	return f[ls]>f[rs]?ls:rs;
}
int main()
{
	scanf("%d%d",&n,&m);
	int tp=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		q[a].emplace_back(b,c);
		vs[++tp]=b,vs[++tp]=c;
	}
	sort(vs+1,vs+tp+1);
	d=unique(vs+1,vs+tp+1)-vs-1;
	for(int i=1;i<=n;i++)
		for(pii &t:q[i])
		{
			t.fi=lower_bound(vs+1,vs+d+1,t.fi)-vs;
			t.se=lower_bound(vs+1,vs+d+1,t.se)-vs;
		}
	int mv=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=1,pr[i]=0;
		for(pii t:q[i])
		{
			// printf("d:%d i:%d l:%d r:%d\n",d,i,t.fi,t.se);
			int p=askmx(1,1,d,t.fi,t.se);
			if(f[p]+1>f[i])
				f[i]=f[p]+1,pr[i]=p;
		}
		if(f[i]>f[mv])
			mv=i;
		for(pii t:q[i])
			setmx(1,1,d,t.fi,t.se,i);
	}
	int p=mv;
	if(p==0)
		p=1;
	set<int> ts;
	for(;p;p=pr[p])
		ts.insert(p);
	printf("%d\n",n-(int)ts.size());
	for(int i=1;i<=n;i++)
		if(!ts.count(i))
			printf("%d ",i);
	return 0;
}