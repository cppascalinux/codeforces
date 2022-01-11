#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
#define ln long long
using namespace std;
int n,k;
int s[200009];
ln sm[4000009],lz[4000009];
void down(int a,int l,int r)
{
	int la=a<<1,ra=a<<1|1,mid=(l+r)>>1;
	ln &v=lz[a];
	lz[la]+=v,lz[ra]+=v;
	sm[la]+=v*(mid-l+1),sm[ra]+=v*(r-mid);
	v=0;
}
void add(int a,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
	{
		sm[a]+=(ln)v*(r-l+1);
		lz[a]+=v;
		return;
	}
	down(a,l,r);
	int mid=(l+r)>>1;
	add(a<<1,l,mid,ll,rr,v);
	add(a<<1|1,mid+1,r,ll,rr,v);
	sm[a]=sm[a<<1]+sm[a<<1|1];
}
int ask(int a,int l,int r,int v)
{
	if(l==r)
		return l;
	int la=a<<1,ra=a<<1|1,mid=(l+r)>>1;
	down(a,l,r);
	if(v<=sm[la])
		return ask(la,l,mid,v);
	else
		return ask(ra,mid+1,r,v-sm[la]);
}
int main()
{
	scanf("%d%d",&n,&k);
	// n=200000,k=1000000000;
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	// for(int i=1;i<=n;i++)
	// 	s[i]=200000;
	sort(s+1,s+n+1,greater<int>());
	int up=800000;
	add(1,0,up,0,0,1);
	int ans=inf;
	for(int i=1;i<=n;i++)
	{
		int p=ask(1,0,up,1);
		add(1,0,up,p,p,-1);
		int l=(s[i]-1)/2;
		add(1,0,up,p+2,p+2+l-1,2);
		if(s[i]%2==0)
			add(1,0,up,p+2+l,p+2+l,1);
		if(sm[1]>=k)
			ans=min(ans,ask(1,0,up,k));
		// printf("i:%d sm1:%d l:%d\n",i,sm[1],l);
	}
	printf("%d",ans>=inf?-1:ans);
	return 0;
}