#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int n;
ll l,r,z;
int cb[1009][1009];
int f[70][2009];
void init()
{
	int m=1000;
	for(int i=0;i<=m;i++)
		cb[i][0]=cb[i][i]=1;
	for(int i=2;i<=m;i++)
		for(int j=1;j<=i-1;j++)
			cb[i][j]=(cb[i-1][j]+cb[i-1][j-1])%mod;
}
int cal(ll v,ll z)
{
	memset(f,0,sizeof(f));
	f[62][0]=1;
	for(int i=61;i>=0;i--)
	{
		for(int j=0;j<=2*n;j++)//inherit from last
		{
			int tj=j+((v>>i)&1);
			for(int k=z>>i&1;k<=tj;k+=2)
			{
				f[i][min((tj-k)*2,2*n)]=(f[i][min((tj-k)*2,2*n)]+(ll)f[i+1][j]*cb[n][min(k,1002)])%mod;
			}
		}
	}
	int ans=0;
	// for(int i=0;i<=3;i++)
	// 	for(int j=0;j<=n;j++)
	// 		printf("i:%d j:%d f:%d\n",i,j,f[i][j]);
	for(int i=0;i<=2*n;i++)
		ans=(ans+f[0][i])%mod;
	return ans;
}
int main()
{
	init();
	scanf("%d%lld%lld%lld",&n,&l,&r,&z);
	// printf("cal 5 1:%d\n",cal(5,1));
	int ans=(cal(r,z)-cal(l-1,z)+mod)%mod;
	// ans=cal(r,z);
	printf("%d",ans);
	return 0;
}