#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
vector<int> g[209];
int f[209],sz[209];
int cb[209][209],pb[209][209];
int inv2[209];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
int inv(int x)
{
	return qpow(x,mod-2);
}
void dfs(int x,int fa)
{
	f[x]=fa;
	sz[x]=1;
	for(int v:g[x])
		if(v!=fa)
		{
			dfs(v,x);
			sz[x]+=sz[v];
		}
}
void init()
{
	for(int i=0;i<=n;i++)
		cb[i][0]=cb[i][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			cb[i][j]=(cb[i-1][j]+cb[i-1][j-1])%mod;
	for(int i=0;i<=n;i++)
		inv2[i]=qpow(qpow(2,i),mod-2);
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			for(int k=j-1;k<=i-2;k++)
			{
				pb[i][j]=(pb[i][j]+(ll)cb[k][j-1]*inv2[k+1])%mod;
			}
			// printf("i:%d j:%d pb:%d\n",i,j,pb[i][j]);
		}
}
int main()
{
	scanf("%d",&n);
	init();
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i-1;j++)
		{
			dfs(j,0);
			ans=(ans+(ll)inv(n)*sz[i])%mod;
			int num=0;
			for(int v=i;v!=j;v=f[v])
				num++;
			int in=inv(n)%mod;
			for(int v=f[i],u=i,k=1;v!=j;v=f[v],u=f[u],k++)
			{
				// printf("v:%d u:%d sz:%d\n",v,u,sz[v]-sz[u]);
				ans=(ans+(ll)in*pb[num][k]%mod*(sz[v]-sz[u]))%mod;
			}
			// printf("i:%d j:%d ans:%d\n",i,j,ans);
		}
	printf("%d\n",ans);
	return 0;
}