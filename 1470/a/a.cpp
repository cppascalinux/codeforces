#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m;
int k[300009],c[300009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",k+i);
		for(int i=1;i<=m;i++)
			scanf("%d",c+i);
		sort(k+1,k+n+1);
		ll ans=0;
		int tp=0;
		for(int i=n;i>=1;i--)
		{
			if(k[i]>tp+1)
				ans+=c[++tp];
			else
				ans+=c[k[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}