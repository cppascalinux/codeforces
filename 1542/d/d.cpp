#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n;
char t[10];
int s[509];
int f[509][509];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",t+1);
		if(t[1]=='-')
			s[i]=0;
		else
			scanf("%d",s+i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(s[i])
		{
			memset(f,0,sizeof(f));
			f[0][0]=1;
			for(int j=1;j<=n;j++)
			{
				for(int k=0;k<=j;k++)
					f[j][k]=f[j-1][k];
				if(j==i)
					continue;
				if(s[j]==0)
				{
					if(j<i)
						(f[j][0]+=f[j-1][0])%=mod;
					for(int k=0;k<=j;k++)
						(f[j][k]+=f[j-1][k+1])%=mod;
				}
				else
				{
					if(s[j]<s[i]||(s[j]==s[i]&&j<i))
					{
						for(int k=1;k<=j;k++)
							(f[j][k]+=f[j-1][k-1])%=mod;
					}
					else
						for(int k=0;k<=j;k++)
							(f[j][k]+=f[j-1][k])%=mod;
				}
			}
			int sm=0;
			for(int i=0;i<=n;i++)
				(sm+=f[n][i])%=mod;
			ans=(ans+(ll)sm*s[i])%mod;
		}
	printf("%d",ans);
	return 0;
}