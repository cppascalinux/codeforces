#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
ll s[500009];
int sm[100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",s+i);
		for(int i=0;i<=61;i++)
			sm[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=61;j++)
				if(s[i]>>j&1)
					(sm[j]+=(1LL<<j)%mod)%=mod;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int sm1=0,sm2=(ll)n*(s[i]%mod)%mod;
			for(int j=0;j<=61;j++)
				if(s[i]>>j&1)
					(sm1+=sm[j])%=mod;
				else
					(sm2+=sm[j])%=mod;
			ans=(ans+(ll)sm1*sm2)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}