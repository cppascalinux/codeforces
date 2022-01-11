#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,k;
int mul[100009],inv[100009];
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
	for(int i=1;i<=100000;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[100000]=qpow(mul[100000],mod-2);
	for(int i=100000;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
}
int cb(int a,int b)
{
	if(a<0||b<0||b>a)
		return 0;
	return (ll)mul[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
	init();
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d",&n,&k);
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			if(i*k>1e8)
				break;
			int iv=qpow(cb(n,i),mod-2);
			ans=(ans+(ll)cb(n-(i-1)*(k-1),i)*iv)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}