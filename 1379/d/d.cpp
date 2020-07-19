#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define PII pair<int,int>
#define FI first
#define SE second
using namespace std;
int n,h,m,k,rt,cnt;
int sh[100009],sm[100009];
int mn[10000009],mps[10000009],ls[10000009],rs[10000009],ad[10000009];
void down(int a,int l,int r)
{
	if(!ls[a])
	{
		ls[a]=++cnt;
		mps[ls[a]]=l;
	}
	if(!rs[a])
	{
		rs[a]=++cnt;
		int mid=(l+r)>>1;
		mps[rs[a]]=mid+1;
	}
	mn[ls[a]]+=ad[a];
	mn[rs[a]]+=ad[a];
	ad[ls[a]]+=ad[a];
	ad[rs[a]]+=ad[a];
	ad[a]=0;
}
void add(int &a,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll)
		return;
	if(!a)
	{
		a=++cnt;
		mps[a]=l;
	}
	if(l>=ll&&r<=rr)
	{
		mn[a]+=v;
		ad[a]+=v;
		return;
	}
	down(a,l,r);
	int mid=(l+r)>>1;
	add(ls[a],l,mid,ll,rr,v);
	add(rs[a],mid+1,r,ll,rr,v);
	mn[a]=min(mn[ls[a]],mn[rs[a]]);
	mps[a]=mn[ls[a]]<=mn[rs[a]]?mps[ls[a]]:mps[rs[a]];
}
void init()
{
	m>>=1;
	for(int i=1;i<=n;i++)
		if(sm[i]>=m)
			sm[i]-=m;
	for(int i=1;i<=n;i++)
	{
		int st=sm[i]+1,ed=sm[i]+k-1;
		if(st>ed)
			continue;
		if(ed<=m-1)
			add(rt,0,m-1,st,ed,1);
		else if(st<=m-1)
		{
			add(rt,0,m-1,st,m-1,1);
			add(rt,0,m-1,0,ed-m,1);
		}
		else
			add(rt,0,m-1,st-m,ed-m,1);
	}
}
void solve()
{
	int p=mps[rt];
	int v=mn[rt];
	printf("%d %d\n",v,p);
	for(int i=1;i<=n;i++)
	{
		int st=sm[i]+1,ed=sm[i]+k-1;
		if(st>ed)
			continue;
		if(ed<=m-1)
		{
			if(p>=st&&p<=ed)
				printf("%d ",i);
		}
		else if(st<=m-1)
		{
			if((p>=st&&p<=m-1)||(p>=0&&p<=ed-m))
				printf("%d ",i);
		}
		else
		{
			if(p>=st-m&&p<=ed-m)
				printf("%d ",i);
		}
	}
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	scanf("%d%d%d%d",&n,&h,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",sh+i,sm+i);
	init();
	solve();
	return 0;
}