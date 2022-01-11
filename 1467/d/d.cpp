#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
int n,k,q;
int f[5009][5009];
int s[5009],rp[5009];
void dp()
{
	for(int i=1;i<=n;i++)
		f[0][i]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j]+=j>1?f[i-1][j-1]:0;
			f[i][j]+=j<n?f[i-1][j+1]:0;
			f[i][j]-=f[i][j]>=mod?mod:0;
		}
}
void getrp()
{
	for(int j=0;j<=k;j++)
		for(int i=1;i<=n;i++)
			rp[i]=(rp[i]+(ll)f[j][i]*f[k-j][i])%mod;
}
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	dp();
	getrp();
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+(ll)s[i]*rp[i])%mod;
	for(int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ans=((ans+(ll)(b-s[a])*rp[a])%mod+mod)%mod;
		printf("%d\n",ans);
		s[a]=b;
	}
	return 0;
}