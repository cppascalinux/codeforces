#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
int sa[1009],sb[1009];
int rt[2][16384],mp[16384];
int mul[200009],inv[200009];
int f[16384],g[16384];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void initfft(int l)
{
	int bit=0;
	while((1<<bit)<l+1)
		bit++;
	m=1<<bit;
	rt[0][0]=rt[1][0]=1;
	rt[0][1]=qpow(3,(mod-1)/m);
	for(int i=2;i<m;i++)
		rt[0][i]=(ll)rt[0][i-1]*rt[0][1]%mod;
	for(int i=1;i<m;i++)
		rt[1][i]=rt[0][m-i];
	for(int i=1;i<m;i++)
		mp[i]=(mp[i>>1]>>1)|((i&1)<<(bit-1));
}
void initmul()
{
	int mx=200000;
	mul[0]=1;
	for(int i=1;i<=mx;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[mx]=qpow(mul[mx],mod-2);
	for(int i=mx;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
}
void fft(int *s,int c)
{
	for(int i=0;i<m;i++)
		if(i<mp[i])
			swap(s[i],s[mp[i]]);
	for(int i=2;i<=m;i<<=1)
	{
		int d=i>>1,st=m/i;
		for(int j=0;j<m;j+=i)
			for(int k=0;k<d;k++)
			{
				int t=(ll)s[j+k+d]*rt[c][st*k]%mod;
				s[j+k+d]=(s[j+k]-t+mod)%mod;
				s[j+k]=(s[j+k]+t)%mod;
			}
	}
	if(c)
	{
		int im=qpow(m,mod-2);
		for(int i=0;i<m;i++)
			s[i]=(ll)s[i]*im%mod;
	}
}
int cb(int a,int b)
{
	return b>a||b<0?0:(ll)mul[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve()
{
	int sm=1;
	f[1]=1;
	for(int i=1;i<=n;i++)
	{
		int nsm=sm+sa[i]-sb[i];
		memset(g,0,sizeof(g));
		for(int j=0;j<=nsm+sm-2;j++)
			g[j]=cb(sa[i]+sb[i],sb[i]+1-sm+j);
		initfft(nsm+sm-2+sm);
		fft(f,0);
		fft(g,0);
		for(int j=0;j<m;j++)
			f[j]=(ll)f[j]*g[j]%mod;
		fft(f,1);
		f[0]=0;
		for(int j=1;j<=nsm;j++)
			f[j]=f[j+sm-1];
		sm=nsm;
		for(int j=sm+1;j<m;j++)
			f[j]=0;
		// printf("i:%d\n",i);
		// for(int j=1;j<=sm;j++)
		// 	printf("%d ",f[j]);
		// printf("\n");
	}
	int ans=0;
	for(int i=1;i<=sm;i++)
		(ans+=f[i])%=mod;
	printf("%d",ans);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",sa+i,sb+i);
	initmul();
	solve();
	return 0;
}