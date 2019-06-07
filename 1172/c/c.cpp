#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define li long long
#define mod 998244353
using namespace std;
int n,m;
int f[59][209][59],g[59][209];
int w[200009],s[200009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(li)a*a%mod)
		if(b&1)
			ans=(li)ans*a%mod;
	return ans;
}
void dp()
{
	int rsm=0;
	for(int i=1;i<=n;i++)
		rsm+=w[i];
	for(int i=1;i<=n;i++)
		f[0][100][i]=w[i];
	g[0][100]=1;
	for(int i=0;i<=m-1;i++)
		for(int j=0;j<=200;j++)
		{
			for(int k=1;k<=n;k++)
			{
				f[i][j][k]=(li)f[i][j][k]*qpow(g[i][j],mod-2)%mod;
				if(f[i][j][k]&&g[i][j])
				{
					int prob=(li)qpow(j-100+rsm,mod-2)*f[i][j][k]%mod;
					// printf("prob:%d\n",prob);
					g[i+1][j+s[k]]=(g[i+1][j+s[k]]+(li)g[i][j]*prob)%mod;
					// g[i+1][j]=(g[i+1][j]+(li)g[i][j]*(mod+1-prob))%mod;
					f[i+1][j+s[k]][k]=(f[i+1][j+s[k]][k]+(li)g[i][j]*prob%mod*(f[i][j][k]+mod+s[k]))%mod;
					for(int l=1;l<=n;l++)
						if(l!=k)
							f[i+1][j+s[k]][l]=(f[i+1][j+s[k]][l]+(li)g[i][j]*prob%mod*f[i][j][l])%mod;
				}
			}
		}
	// for(int j=0;j<=200;j++)
	// 	for(int k=1;k<=n;k++)
	// 		f[m][j][k]=(li)f[m][j][k]*qpow
	for(int i=0;i<=m;i++)
		for(int j=98;j<=102;j++)
		{
			printf("i:%d j:%d g:%d\n",i,j,g[i][j]);
			for(int k=1;k<=n;k++)
				printf("k:%d f:%d\n",k,f[i][j][k]);
		}
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=0;j<=200;j++)
			ans=(ans+f[m][j][i])%mod;
		printf("%d\n",ans);
	}
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		if(s[i]==0)
			s[i]=-1;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",w+i);
	dp();
	return 0;
}