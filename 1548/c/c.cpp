#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,m;
int mul[3000009],inv[3000009];
int f[3000009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void init()
{
	int p=3000005;
	mul[0]=1;
	for(int i=1;i<=p;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[p]=qpow(mul[p],mod-2);
	for(int i=p;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
	// for(int i=0;i<=10;i++)
	// 	printf("i:%d mul:%d inv:%d\n",i,mul[i],inv[i]);
}
int cb(int a,int b)
{
	if(b>a||b<0)
		return 0;
	return (ll)mul[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve()
{
	f[0]=n+1;
	int inv3=qpow(3,mod-2);
	for(int i=1;i<=3*n;i++)
	{
		int t=(cb(3*n+1,i+1)+2LL*cb(3*n+1,i)%mod)%mod;
		(t+=cb(3*n+1,i-1))%=mod;
		// printf("t:%d\n",t);
		t=(t+mod-3LL*f[i-1]%mod)%mod;
		if(i>=2)
			t=(t+mod-f[i-2])%mod;
		t=(ll)t*inv3%mod;
		f[i]=t;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	solve();
	for(int i=1;i<=m;i++)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",f[a]);
	}
	return 0;
}