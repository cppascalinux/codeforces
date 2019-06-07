#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define li long long
#define mod 998244353
using namespace std;
int n,tot,ans=1;
int mul[200009],inv[200009];
int hd[200009],eg[400009],nxt[400009];
int sz[200009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(li)a*a%mod)
		if(b&1)
			ans=(li)ans*a%mod;
	return ans;
}
void ins(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void init()
{
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=(li)mul[i-1]*i%mod;
	inv[n]=qpow(mul[n],mod-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=(li)inv[i+1]*(i+1)%mod;
}
void dfs(int x,int fa)
{
	sz[x]=1;
	int sm=0;
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa)
		{
			dfs(eg[i],x);
			sm++;
			sz[x]+=sz[eg[i]];
		}
	ans=(li)ans*mul[sm+(fa!=0)]%mod;
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1,a,b;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		ins(a,b),ins(b,a);
	}
	init();
	dfs(1,0);
	ans=(li)ans*n%mod;
	printf("%d",ans);
	return 0;
}