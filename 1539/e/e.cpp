#include<bits/stdc++.h>
#define inf 0x3F3F3F3F
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
struct seg
{
	int ps[400009],lz[400009];
	seg(){memset(ps,0x3F,sizeof(ps));}
	void down(int a,int l,int r)
	{
		if(lz[a]==-1)
			return;
		int la=a*2,ra=a*2+1,v=lz[a],mid=(l+r)/2;
		lz[la]=lz[a];
		lz[ra]=lz[a];
		ps[la]=v?l:inf;
		ps[ra]=v?mid+1:inf;
		lz[a]=-1;
	}
	void setv(int a,int l,int r,int ll,int rr,int v)
	{
		if(l>rr||r<ll||ll>rr)
			return;
		if(l>=ll&&r<=rr)
		{
			lz[a]=v;
			ps[a]=v?l:inf;
			return;
		}
		down(a,l,r);
		int mid=(l+r)/2;
		setv(a*2,l,mid,ll,rr,v);
		setv(a*2+1,mid+1,r,ll,rr,v);
		ps[a]=min(ps[a*2],ps[a*2+1]);
	}
	int getv(int a,int l,int r,int ps)
	{
		if(l==r)
			return lz[a];
		down(a,l,r);
		int mid=(l+r)/2;
		if(ps<=mid)
			return getv(a*2,l,mid,ps);
		return getv(a*2+1,mid+1,r,ps);
	}
};
seg tl,tr;
int n,m;
int nm[100009];
int al[100009],ar[100009],bl[100009],br[100009];
pii st[100009];
int p[100009],rp[100009];
int lstl[100009],lstr[100009];
int ans[100009];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%d",nm+i,al+i,bl+i,ar+i,br+i);
		st[i]=pii(nm[i],i);
	}
	st[0]=pii(0,0);
	sort(st,st+n+1);
	for(int i=0;i<=n;i++)
		p[st[i].se]=i,rp[i]=st[i].se;
	memset(lstl,0x3F,sizeof(lstl));
	memset(lstr,0x3F,sizeof(lstr));
	int fl=0;
	tl.setv(1,0,n,p[0],p[0],1);
	for(int i=1;i<=n;i++)
	{
		int cl=0,cr=0;
		cl=(nm[i]>=al[i]&&nm[i]<=bl[i]);
		cr=(nm[i]>=ar[i]&&nm[i]<=br[i]);
		if(!cl&&!cr)
		{
			fl=1;
			break;
		}
		int pl=tl.ps[1],pr=tr.ps[1];
		// printf("i:%d p:%d cl:%d cr:%d pl:%d pr:%d\n",i,p[i],cl,cr,pl,pr);
		if(cl)
		{
			int lb=lower_bound(st,st+n+1,pii(ar[i],-1))-st-1;
			int ub=upper_bound(st,st+n+1,pii(br[i],inf))-st;
			// printf("il:%d lb:%d ub:%d\n",i,lb,ub);
			if(pr<inf)
				tl.setv(1,0,n,p[i-1],p[i-1],1);
			tl.setv(1,0,n,0,lb,0);
			tl.setv(1,0,n,ub,n,0);
			lstl[i]=pr;
		}
		else
			tl.setv(1,0,n,0,n,0);
		if(cr)
		{
			int lb=lower_bound(st,st+n+1,pii(al[i],-1))-st-1;
			int ub=upper_bound(st,st+n+1,pii(bl[i],inf))-st;
			// printf("ir:%d lb:%d ub:%d\n",i,lb,ub);
			if(pl<inf)
				tr.setv(1,0,n,p[i-1],p[i-1],1);
			tr.setv(1,0,n,0,lb,0);
			tr.setv(1,0,n,ub,n,0);
			lstr[i]=pl;
		}
		else
			tr.setv(1,0,n,0,n,0);
	}
	if(fl)
		return printf("No"),0;
	int cur=min(tl.ps[1],tr.ps[1]);
	if(cur==inf)
		return printf("No"),0;
	printf("Yes\n");
	int dir=(tr.ps[1]<inf);
	cur=dir?tr.ps[1]:tl.ps[1];
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d lstl:%d lstr:%d\n",i,lstl[i],lstr[i]);
	for(int i=n;i>=1;i--)
	{
		ans[i]=dir;
		// printf("i:%d cur:%d rp:%d\n",i,cur,rp[cur]);
		if(dir==0)
		{
			if(rp[cur]+1==i&&lstl[i]<inf)
				cur=lstl[i],dir=1;
		}
		else
		{
			if(rp[cur]+1==i&&lstr[i]<inf)
				cur=lstr[i],dir=0;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}