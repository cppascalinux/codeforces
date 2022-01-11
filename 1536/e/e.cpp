#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m;
char s[2009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int ans=1,sm=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				if(s[j]=='#')
					ans=(ans*2)%mod;
				else
					sm++;
		}
		if(sm==0)
			ans=(ans+(mod-1))%mod;
		printf("%d\n",ans);
	}
	return 0;
}