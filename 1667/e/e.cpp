#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=998244353;
int n,len;
int mul[200009],inv[200009],it[200009];
int sm[200009],ans[200009];
int mp[270009],rt[2][270009];
int sa[270009],sb[270009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;a=(ll)a*a%mod,b>>=1)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void initm()
{
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[n]=qpow(mul[n],mod-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
	for(int i=1;i<=n;i++)
		it[i]=(ll)mul[i-1]*inv[i]%mod;
}
void initfft(int l)
{
	int bits=0;
	while((1<<bits)<=l)
		bits++;
	len=1<<bits;
	rt[0][0]=rt[1][0]=1;
	rt[0][1]=qpow(3,(mod-1)/len);
	for(int i=2;i<len;i++)
		rt[0][i]=(ll)rt[0][i-1]*rt[0][1]%mod;
	for(int i=1;i<len;i++)
		rt[1][i]=rt[0][len-i];
	for(int i=1;i<len;i++)
		mp[i]=(mp[i>>1]>>1)|((i&1)<<(bits-1));
}
void fft(int *s,int c)
{
	for(int i=0;i<len;i++)
		if(i<mp[i])
			swap(s[i],s[mp[i]]);
	for(int l=2;l<=len;l*=2)
	{
		int d=l/2,p=len/l;
		for(int i=0;i<len;i+=l)
			for(int j=0;j<d;j++)
			{
				int tmp=(ll)s[i+j+d]*rt[c][p*j]%mod;
				s[i+j+d]=(s[i+j]-tmp+mod)%mod;
				s[i+j]=(s[i+j]+tmp)%mod;
			}
	}
	if(c)
	{
		int invn=qpow(len,mod-2);
		for(int i=0;i<len;i++)
			s[i]=(ll)s[i]*invn%mod;
	}
}
int main()
{
	scanf("%d",&n);
	if(n==3)
	{
		printf("1 1 0\n");
		return 0;
	}
	initm();
	initfft(n);
	for(int i=0;i<=(n-3)/2;i++)
		sa[i]=inv[i];
	for(int i=0;i<=(n-3)/2;i++)
		sb[i]=mul[(n-3)/2-i];
	fft(sa,0);
	fft(sb,0);
	for(int i=0;i<len;i++)
		sa[i]=(ll)sa[i]*sb[i]%mod;
	fft(sa,1);
	for(int i=2;i<=(n+1)/2;i++)
		sm[i]=(ll)sa[(n+1)/2-i]*mul[n-i]%mod*(i-1)%mod;
	sm[1]=mul[n-1];
	// for(int i=2;i<=(n+1)/2;i++)
	// {
	// 	for(int j=(n+1)/2;j<=n-i+1;j++)
	// 		sm[i]=(sm[i]+(ll)mul[n-1-j]*(i-1)%mod*mul[n-i]%mod*inv[n-i-j+1])%mod;
	// }
	int tot=0;
	// for(int i=1;i<=(n+1)/2;i++)
	// {
	// 	ans[i]=sm[i];
	// 	for(int j=i+1;j<=(n+1)/2;j++)
	// 		ans[i]=(ans[i]-(ll)sm[j]*it[j-1]%mod+mod)%mod;
	// }
	for(int i=(n+1)/2;i>=1;i--)
	{
		ans[i]=(sm[i]-tot+mod)%mod;
		tot=(tot+(ll)sm[i]*it[i-1])%mod;
	}
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d sm:%d ans:%d\n",i,sm[i],ans[i]);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}