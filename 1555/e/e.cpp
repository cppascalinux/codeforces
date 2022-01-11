#include<bits/stdc++.h>
#define inf 0x3F3F3F3F;
#define long long long
using namespace std;
int n,m;
struct node
{
	int l,r,w;
	bool operator<(const node &p)const{return w<p.w;}
};
node s[300009];
int mn[4000009],lz[4000009];
void dn(int a)
{
	int la=a*2,ra=a*2+1,&v=lz[a];
	if(!v)
		return;
	lz[la]+=v,lz[ra]+=v;
	mn[la]+=v,mn[ra]+=v;
	v=0;
}
void upd(int a)
{
	mn[a]=min(mn[a*2],mn[a*2+1]);
}
void add(int a,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
	{
		lz[a]+=v;
		mn[a]+=v;
		return;
	}
	dn(a);
	int mid=(l+r)/2;
	add(a*2,l,mid,ll,rr,v);
	add(a*2+1,mid+1,r,ll,rr,v);
	upd(a);
}
int ask(int a,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)
		return inf;
	if(l>=ll&&r<=rr)
		return mn[a];
	dn(a);
	int mid=(l+r)/2;
	return min(ask(a*2,l,mid,ll,rr),ask(a*2+1,mid+1,r,ll,rr));
}
int main()
{
	scanf("%d%d",&n,&m);
	m--;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].w);
		s[i].r--;
	}
	sort(s+1,s+n+1);
	int lp=1,ans=inf;
	for(int i=1;i<=n;i++)
	{
		add(1,1,m,s[i].l,s[i].r,1);
		while(lp<=i&&mn[1]>0)
		{
			// printf("i:%d lp:%d mn:%d\n",i,lp,mn[1]);
			ans=min(ans,s[i].w-s[lp].w);
			add(1,1,m,s[lp].l,s[lp].r,-1);
			lp++;
		}
	}
	printf("%d\n",ans);
	return 0;
}