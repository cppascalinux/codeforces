#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,m;
int mul[200009];
int f[200009][2];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d",&n,&m);
		mul[0]=1;
		for(int i=1;i<=n;i++)
			mul[i]=mul[i-1]*2%mod;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i=1;i<=m;i++)
		{
			if(n&1)
			{
				f[i][0]=(ll)f[i-1][0]*(mul[n-1]+1)%mod;
			}
			else
			{
				f[i][0]=(ll)f[i-1][0]*(mul[n-1]+mod-1)%mod;
				f[i][1]=((ll)f[i-1][1]*mul[n]+f[i-1][0])%mod;
			}
		}
		int ans=(f[m][0]+f[m][1])%mod;
		printf("%d\n",ans);
	}
	return 0;
}