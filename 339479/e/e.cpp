#include<bits/stdc++.h>
#define ll long long
#define db double
#define mod 998244353
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,tot;
int pm[100009],vis[100009],phi[100009];
int l[60],r[60];
int f[100009],g[100009];
void init()
{
	phi[1]=1;
	for(int i=2;i<=m;i++)
	{
		if(!vis[i])
		{
			pm[++tot]=i;
			phi[i]=-1;
		}
		for(int j=1;j<=tot&&i*pm[j]<=m;j++)
		{
			vis[i*pm[j]]=1;
			if(i%pm[j]==0)
				phi[i*pm[j]]=0;
			else
				phi[i*pm[j]]=-phi[i];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++)
		scanf("%d%d",l+i,r+i);
	int ans=0;
	for(int i=1;i<=m;i++)
		if(phi[i])
		{
			for(int j=0;i*j<=m;j++)
				f[j]=1;
			for(int j=1;j<=n;j++)
			{
				int up=r[j]/i,dn=(l[j]+i-1)/i;
				int lp=0,rp=-1,sm=0;
				for(int k=0;i*k<=m;k++)
					g[k]=0;
				for(int k=dn;i*k<=m;k++)
				{
					if(rp<k-dn)
					{
						rp++;
						sm=(sm+f[rp])%mod;
					}
					if(lp<k-up)
					{
						sm=(sm-f[lp]+mod)%mod;
						lp++;
					}
					g[k]=sm;
				}
				for(int k=0;i*k<=m;k++)
					f[k]=g[k];
			}
			ans=(ans+(ll)(mod+phi[i])*f[m/i])%mod;
		}
	printf("%d",ans);
	return 0;
}