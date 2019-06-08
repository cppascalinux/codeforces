#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define li long long
#define mod 998244353
using namespace std;
int n,m;
int s[200009],w[200009];
int f[3009][3009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(li)a*a%mod)
		if(b&1)
			ans=(li)ans*a%mod;
	return ans;
}
void solve()
{
	int w0=0,w1=0;
	for(int i=1;i<=n;i++)
		if(s[i])
			w1+=w[i];
		else
			w0+=w[i];
	f[0][0]=1;
	for(int i=0;i<=m-1;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int prob=(li)(w1+j)*qpow(((li)mod+w0-(i-j)+w1+j)%mod,mod-2)%mod;
			f[i+1][j+1]=(f[i+1][j+1]+(li)f[i][j]*prob)%mod;
			f[i+1][j]=(f[i+1][j]+(li)f[i][j]*(mod+1-prob))%mod;
		}
	}
	int ans0=0,ans1=0;
	for(int i=0;i<=m;i++)
	{
		ans0=(ans0+(li)f[m][i]*((li)mod+w0-(m-i)))%mod;
		ans1=(ans1+(li)f[m][i]*(w1+i))%mod;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i])
			printf("%lld\n",(li)ans1*qpow(w1,mod-2)%mod*w[i]%mod);
		else
			printf("%lld\n",(li)ans0*qpow(w0,mod-2)%mod*w[i]%mod);
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
		scanf("%d",s+i);
	for(int i=1;i<=n;i++)
		scanf("%d",w+i);
	solve();
	return 0;
}