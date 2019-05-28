//2019.05.28
//CF1083D The Fair Nut's getting crazy 对于所有合法的[b,c],答案为(b-maxpre)*(minnxt-c)
//从右向左枚举b,用单调栈维护最大,最小值,在线段树上记录max*min,max*c,min的和,每次在线段树上区间乘即可
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define li long long
#define mod 1000000007
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n;
int s[100009],sv[100009];
int pos[100009],pre[100009],nxt[100009];
int mr[100009];
int sm1[400009],sm2[400009],sm3[400009],lz1[400009],lz2[400009];
pii st1[100009],st2[100009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(li)a*a%mod)
		if(b&1)
			ans=(li)ans*a%mod;
	return ans;
}
void down(int a)
{
	int t1=lz1[a],t2=lz2[a];
	int la=a<<1,ra=a<<1|1;
	if(t1!=1)
	{
		lz1[la]=(li)lz1[la]*t1%mod,lz1[ra]=(li)lz1[ra]*t1%mod;
		sm1[la]=(li)sm1[la]*t1%mod,sm1[ra]=(li)sm1[ra]*t1%mod;
		sm3[la]=(li)sm3[la]*t1%mod,sm3[ra]=(li)sm3[ra]*t1%mod;
	}
	if(t2!=1)
	{
		lz2[la]=(li)lz2[la]*t2%mod,lz2[ra]=(li)lz2[ra]*t2%mod;
		sm2[la]=(li)sm2[la]*t2%mod,sm2[ra]=(li)sm2[ra]*t2%mod;
		sm3[la]=(li)sm3[la]*t2%mod,sm3[ra]=(li)sm3[ra]*t2%mod;
	}
	lz1[a]=lz2[a]=1;
}
void update(int a)
{
	int la=a<<1,ra=a<<1|1;
	sm1[a]=(sm1[la]+sm1[ra])%mod;
	sm2[a]=(sm2[la]+sm2[ra])%mod;
	sm3[a]=(sm3[la]+sm3[ra])%mod;
}
void build(int a,int l,int r)
{
	lz1[a]=lz2[a]=1;
	if(l==r)
	{
		sm1[a]=nxt[l];
		sm2[a]=(li)pre[l]*l%mod;
		sm3[a]=(li)pre[l]*nxt[l]%mod;
	}
	else
	{
		int mid=(l+r)>>1;
		build(a<<1,l,mid);
		build(a<<1|1,mid+1,r);
		update(a);
	}
}
void add(int a,int l,int r,int ll,int rr,int val1,int val2)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
	{
		if(val1!=1)
		{
			lz1[a]=(li)lz1[a]*val1%mod;
			sm1[a]=(li)sm1[a]*val1%mod;
			sm3[a]=(li)sm3[a]*val1%mod;
		}
		if(val2!=1)
		{
			lz2[a]=(li)lz2[a]*val2%mod;
			sm2[a]=(li)sm2[a]*val2%mod;
			sm3[a]=(li)sm3[a]*val2%mod;
		}
		return;
	}
	down(a);
	int mid=(l+r)>>1;
	add(a<<1,l,mid,ll,rr,val1,val2);
	add(a<<1|1,mid+1,r,ll,rr,val1,val2);
	update(a);
}
void setv(int a,int l,int r,int pos,int val1,int val2,int val3)
{
	if(l==r)
		return sm1[a]=val1,sm2[a]=val2,sm3[a]=val3,void();
	down(a);
	int mid=(l+r)>>1;
	if(pos<=mid)
		setv(a<<1,l,mid,pos,val1,val2,val3);
	else
		setv(a<<1|1,mid+1,r,pos,val1,val2,val3);
	update(a);
}
void ask(int a,int l,int r,int ll,int rr,int &val1,int &val2,int &val3)
{
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr)
	{
		val1=(val1+sm1[a])%mod;
		val2=(val2+sm2[a])%mod;
		val3=(val3+sm3[a])%mod;
		return;
	}
	down(a);
	int mid=(l+r)>>1;
	ask(a<<1,l,mid,ll,rr,val1,val2,val3);
	ask(a<<1|1,mid+1,r,ll,rr,val1,val2,val3);
}
void init()
{
	memcpy(sv,s,sizeof(s));
	sort(sv+1,sv+n+1);
	int d=unique(sv+1,sv+n+1)-sv-1;
	for(int i=1;i<=n;i++)
		s[i]=lower_bound(sv+1,sv+d+1,s[i])-sv;
	for(int i=1;i<=n;i++)
		pre[i]=pos[s[i]]+1,pos[s[i]]=i;
	for(int i=1;i<=d;i++)
		pos[i]=n+1;
	for(int i=n;i>=1;i--)
		nxt[i]=pos[s[i]]-1,pos[s[i]]=i;
	mr[n+1]=n;
	for(int i=n;i>=1;i--)
		mr[i]=min(mr[i+1],nxt[i]);
}
void solve()
{
	int ans=0,tp1=0,tp2=0;
	build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		// setv(1,1,n,i,nxt[i],(li)pre[i]*i%mod,(li)nxt[i]*pre[i]%mod);
		// printf("i:%d-------------------------------\n",i);
		int d=i;
		while(tp1&&nxt[i]<=st1[tp1].fi)
		{
			int val=(li)qpow(st1[tp1].fi,mod-2)*nxt[i]%mod;
			add(1,1,n,d+1,st1[tp1].se,val,1);
			d=st1[tp1--].se;
		}
		st1[++tp1]=pii(nxt[i],d);

		d=i;
		while(tp2&&pre[i]>=st2[tp2].fi)
		{
			int val=(li)qpow(st2[tp2].fi,mod-2)*pre[i]%mod;
			add(1,1,n,d+1,st2[tp2].se,1,val);
			d=st2[tp2--].se;
		}
		st2[++tp2]=pii(pre[i],d);

		// for(int j=i;j<=mr[i];j++)
		// {
		// 	int v1=0,v2=0,v3=0;
		// 	ask(1,1,n,j,j,v1,v2,v3);
		// 	printf("j:%d v1:%d v2:%d v3:%d\n",j,v1,v2,v3);
		// }
		int v1=0,v2=0,v3=0;
		ask(1,1,n,i,mr[i],v1,v2,v3);
		ans=((ans+(li)i*v1+v2-v3-(li)i*((li)(mr[i]+i)*(mr[i]-i+1)/2))%mod+mod)%mod;
		// printf("ans:%d\n",ans);
	}
	printf("%d",ans);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("crazy.in","r",stdin);
	freopen("crazy.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	init();
	solve();
	return 0;
}