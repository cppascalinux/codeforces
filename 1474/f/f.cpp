#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define mod 998244353
#define ll long long
using namespace std;
int n;
ll s[55];
ll p[55];
int on[55];
struct node
{
	int id,typ;
	ll h;
	bool operator<(const node &p)const{return h<p.h||(h==p.h&&typ<p.typ);}
};
node st[109];
struct mat
{
	int n,m[55][55];
	mat(){memset(m,0,sizeof(m));}
	mat(int x){n=x;memset(m,0,sizeof(m));}
	mat operator+(const mat &p)const
	{
		assert(n==p.n);
		mat ans(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans.m[i][j]=(m[i][j]+p.m[i][j])%mod;
		return ans;
	}
	mat operator-(const mat &p)const
	{
		assert(n==p.n);
		mat ans(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans.m[i][j]=(m[i][j]-p.m[i][j]+mod)%mod;
		return ans;
	}
	mat operator*(const mat &p)const
	{
		assert(n==p.n);
		mat ans(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				ll sm0=0,sm1=0;
				// int t=n^(n&1);
				for(int k=1;k<=n;k+=2)
				{
					(sm0+=(ll)m[i][k]*p.m[k][j])%=mod;
					(sm1+=(ll)m[i][k+1]*p.m[k+1][j])%=mod;
				}
				// if(n&1)
				// 	(sm0+=(ll)m[i][n]*p.m[n][j])%=mod;
				ans.m[i][j]=(sm0+sm1)%mod;
			}
		return ans;
	}
};
mat qpow(mat a,ll b)
{
	assert(b>=0);
	mat ans(a.n);
	for(int i=1;i<=a.n;i++)
		ans.m[i][i]=1;
	for(;b;b>>=1,a=a*a)
		if(b&1)
			ans=ans*a;
	return ans;
}
int cal(int n)
{
	if(n==1)
		return 1;
	int tp=0;
	for(int i=1;i<=n;i++)
	{
		ll a,b;
		if(i&1)
			a=p[i-1]+1,b=p[i];
		else
			a=p[i],b=p[i-1]-1;
		a=max(a,1LL),b=min(b,p[n]-1);
		// if(a>b)
		// 	continue;
		st[++tp]=node{i,1,a-1};
		st[++tp]=node{i,0,b+1};
	}
	sort(st+1,st+tp+1);
	mat mul(n),ans(n);
	for(int i=1;i<=n;i++)
		ans.m[i][i]=1;
	ll ls=0;
	for(int i=1;i<=tp;i++)
	{
		// printf("i:%d id:%d typ:%d h:%lld\n",i,st[i].id,st[i].typ,st[i].h);
		if(st[i].typ==0)
		{
			ans=qpow(mul,st[i].h-ls)*ans;
			ls=st[i].h;
			on[st[i].id]=0;
			for(int j=1;j<=n;j++)
				mul.m[st[i].id][j]=mul.m[j][st[i].id]=0;
		}
		else
		{
			ans=qpow(mul,st[i].h-ls)*ans;
			ls=st[i].h;
			on[st[i].id]=1;
			for(int j=1;j<st[i].id;j++)
				if(on[j])
					mul.m[st[i].id][j]=1;
			for(int j=st[i].id+1;j<=n;j++)
				if(on[j])
					mul.m[j][st[i].id]=1;
			mul.m[st[i].id][st[i].id]=st[i].id&1;
		}
		// for(int i=1;i<=n;i++)
		// 	for(int j=1;j<=n;j++)
		// 		printf("%d%c",mul.m[i][j],j==n?'\n':' ');
	}
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++)
	// 		printf("%d%c",ans.m[i][j],j==n?'\n':' ');
	return ans.m[n][1];
}
void dp()
{
	ll mx=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			mx=max(mx,s[j]-s[i]+1);
	assert(mx>1);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(s[j]-s[i]+1==mx)
			{
				for(int k=i;k<=j;k++)
					p[k-i]=s[k]-s[i];
				(ans+=cal(j-i))%=mod;
				// printf("i:%d j:%d ans:%d\n",i,j,ans);
			}
	printf("%lld %d",mx,ans);
}
int main()
{
	int a;
	scanf("%d%d",&n,&a);
	int tp=0,ls=0;
	ll sm=0;
	s[++tp]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(!a)
			continue;
		if((ll)a*ls<0)
			s[++tp]=sm;
		sm+=a;
		ls=a;
		// printf("i:%d a:%d ls:%d tp:%d sm:%lld\n",i,a,ls,tp,sm);
	}
	if(ls)
		s[++tp]=sm;
	if(tp<=2)
	{
		if(tp==1)
			printf("1 1");
		else if(s[2]>0)
			printf("%lld 1",s[2]+1);
		else
			printf("1 %d",(int)((1-s[2])%mod));
		return 0;
	}
	n=tp;
	// for(int i=1;i<=n;i++)
	// 	printf("%lld ",s[i]);
	// printf("\n");
	dp();
	return 0;
}