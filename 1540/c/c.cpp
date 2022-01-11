#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define mod 1000000007
using namespace std;
int n,m;
int c[109],b[109];
int smb[109],ssb[109];
int f[109][10009],sf[109][10009],g[10009];
int pt[109],smc[109];
int mo(int x)
{
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int mn=i*x+ssb[i-1],lp=0;
		ll sm=0;
		for(int j=0;j<=smc[i];j++)
		{
			sm+=f[i-1][j];
			(lp<j-c[i])&&(sm+=mod-f[i-1][lp]);
			lp+=(lp<j-c[i]);
			// printf("i:%d j:%d lp:%d sm:%d\n",i,j,lp,sm);
			f[i][j]=j>=mn?sm%mod:0;
		}
	}
	int ans=0;
	for(int i=0;i<=smc[n];i++)
		ans=(ans+f[n][i])%mod;
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
		smc[i]=smc[i-1]+c[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d",b+i);
		smb[i]=smb[i-1]+b[i];
		ssb[i]=ssb[i-1]+smb[i];
	}
	map<int,int> ans;
	int lb=(-ssb[n-1])/n-5;
	int rb=(smc[n]-ssb[n-1])/n+5;
	for(int i=lb;i<=rb;i++)
		ans[i]=mo(i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int a;
		scanf("%d",&a);
		if(a<lb)
			printf("%d\n",ans[lb]);
		else if(a>rb)
			printf("0\n");
		else
			printf("%d\n",ans[a]);
	}
	return 0;
}