#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define inf 0x3F3F3F3F
#define ninf 0xC0C0C0C0
using namespace std;
int n;
int s[200009],ans[200009];
pii p[200009];
int mn[800009],mx[800009],lz[800009];
void upd(int a)
{
	int la=a*2,ra=la+1;
	mn[a]=min(mn[la],mn[ra]);
	mx[a]=max(mx[la],mx[ra]);
}
void down(int a)
{
	if(!lz[a])
		return;
	int la=a*2,ra=la+1,v=lz[a];
	lz[la]+=v,lz[ra]+=v;
	mn[la]+=v,mn[ra]+=v;
	mx[la]+=v,mx[ra]+=v;
	lz[a]=0;
}
void add(int a,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll||ll>rr)
		return;
	if(l>=ll&&r<=rr)
	{
		mn[a]+=v;
		mx[a]+=v;
		lz[a]+=v;
		return;
	}
	down(a);
	int mid=(l+r)/2;
	add(a*2,l,mid,ll,rr,v);
	add(a*2+1,mid+1,r,ll,rr,v);
	upd(a);
}
int ask(int a,int l,int r,int ll,int rr,int typ)
{
	if(l>rr||r<ll||ll>rr)
		return typ?ninf:inf;
	if(l>=ll&&r<=rr)
		return typ?mx[a]:mn[a];
	down(a);
	int mid=(l+r)/2;
	int lsm=ask(a*2,l,mid,ll,rr,typ);
	int rsm=ask(a*2+1,mid+1,r,ll,rr,typ);
	return typ?max(lsm,rsm):min(lsm,rsm);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		p[i]=pii(s[i],i);
	}
	sort(p+1,p+n+1);
	p[n+1].fi=inf;
	for(int i=1;i<=n;i++)
		add(1,0,n,i,i,i);
	int lp=0;
	for(int i=1;i<=n;i++)
	{
		int id=p[i].se,v=p[i].fi;
		while(lp<n&&p[lp+1].fi<v)
		{
			lp++;
			add(1,0,n,p[lp].se,n,-2);
		}
		int lsm=ask(1,0,n,0,id-1,0);
		int rsm=ask(1,0,n,id,n,1);
		ans[id]=max(ans[id],(rsm-lsm)/2);
	}
	memset(mn,0,sizeof(mn));
	memset(mx,0,sizeof(mx));
	memset(lz,0,sizeof(lz));
	for(int i=1;i<=n;i++)
		add(1,0,n,i,i,-i);
	lp=0;
	for(int i=1;i<=n;i++)
	{
		int id=p[i].se,v=p[i].fi;
		while(lp<n&&p[lp+1].fi<=v)
		{
			lp++;
			add(1,0,n,p[lp].se,n,2);
		}
		int lsm=ask(1,0,n,0,id-1,0);
		int rsm=ask(1,0,n,id,n,1);
		ans[id]=max(ans[id],(rsm-lsm-1)/2);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}