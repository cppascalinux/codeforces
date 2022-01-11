#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,ansp;
int s[200009];
int lz[800009],mx[800009],mn[800009];
long sm[800009];
void upd(int a)
{
	sm[a]=sm[a*2]+sm[a*2+1];
	mx[a]=mx[a*2];
	mn[a]=mn[a*2+1];
}
void build(int a,int l,int r)
{
	if(l==r)
		return sm[a]=mx[a]=mn[a]=s[l],void();
	int mid=(l+r)/2;
	build(a*2,l,mid);
	build(a*2+1,mid+1,r);
	upd(a);
}
void down(int a,int l,int r)
{
	if(!lz[a])
		return;
	int la=a*2,ra=a*2+1,v=lz[a],mid=(l+r)/2;
	lz[la]=lz[ra]=v;
	sm[la]=(long)(mid-l+1)*v;
	sm[ra]=(long)(r-mid)*v;
	mx[la]=mx[ra]=v;
	mn[la]=mn[ra]=v;
	lz[a]=0;
}
int fndv(int a,int l,int r,int ll,int rr,int v)//first position to <= v in [ll,rr]
{
	if(l>rr||r<ll)
		return 0;
	int mid=(l+r)/2;
	if(l>=ll&&r<=rr)
	{
		if(l==r)
			return mx[a]<=v?l:0;
		down(a,l,r);
		if(mn[a*2]<=v)
			return fndv(a*2,l,mid,ll,rr,v);
		return fndv(a*2+1,mid+1,r,ll,rr,v);
	}
	down(a,l,r);
	int t=fndv(a*2,l,mid,ll,rr,v);
	if(t)
		return t;
	return fndv(a*2+1,mid+1,r,ll,rr,v);
}
int fndsm(int a,int l,int r,int ll,int rr,int &v)//last pos for 
{
	if(l>rr||r<ll)
		return 0;
	// printf("l:%d r:%d v:%d\n",l,r,v);
	int mid=(l+r)/2;
	if(l>=ll&&r<=rr)
	{
		if(v>=sm[a])
		{
			v-=sm[a];
			return r;
		}
		if(l==r)
			return 0;
		down(a,l,r);
		if(v<=sm[a*2])
			return fndsm(a*2,l,mid,ll,rr,v);
		v-=sm[a*2];
		return max(mid,fndsm(a*2+1,mid+1,r,ll,rr,v));
	}
	down(a,l,r);
	int t=fndsm(a*2,l,mid,ll,rr,v);
	if(mid>=ll&&t<mid)
		return t;
	return max(t,fndsm(a*2+1,mid+1,r,ll,rr,v));
}
void setv(int a,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
	{
		sm[a]=(long)v*(r-l+1);
		mn[a]=mx[a]=v;
		lz[a]=v;
		return;
	}
	down(a,l,r);
	int mid=(l+r)/2;
	setv(a*2,l,mid,ll,rr,v);
	setv(a*2+1,mid+1,r,ll,rr,v);
	upd(a);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			int p=fndv(1,1,n,1,b,c);
			// printf("p:%d\n",p);
			if(p)
				setv(1,1,n,p,b,c);
		}
		else
		{
			int p=b,ans=0;
			while(p<=n)
			{
				p=fndv(1,1,n,p,n,c);
				if(!p)
					break;
				// printf("c:%d ",c);
				int np=fndsm(1,1,n,p,n,c);
				// printf("p:%d np:%d c:%d\n",p,np,c);
				assert(np);
				ans+=np-p+1;
				p=np+1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}