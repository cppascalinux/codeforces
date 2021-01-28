#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
#define ll long long
using namespace std;
int n,k;
int s[1009];
int h1[1009],h2[1009];
int mul[1009],inv[1009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
int cmp(int a,int b)
{
	return a>b;
}
void init()
{
	mul[0]=1;
	for(int i=1;i<=1005;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[1005]=qpow(mul[1005],mod-2);
	for(int i=1005;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
}
int main()
{
	int t;
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),h1[s[i]]++;
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=k;i++)
			h2[s[i]]++;
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=(ll)ans*mul[h1[i]]%mod*inv[h2[i]]%mod*inv[h1[i]-h2[i]]%mod;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			h1[i]=h2[i]=0;
	}
	return 0;
}