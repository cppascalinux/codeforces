#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
int mul[1000009],inv[1000009];
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
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[n]=qpow(mul[n],mod-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
}
int main()
{
	scanf("%d",&n);
	init();
	int ans=0;
	int bg=n&1;
	for(int i=bg;i*2<=n;i+=2)
		ans=(ans+(ll)mul[n-i]*inv[i]%mod*inv[n-2*i]%mod*mul[n-1-i]%mod)%mod;
	ans=(ll)ans*2*n%mod;
	printf("%d",ans);
	return 0;
}