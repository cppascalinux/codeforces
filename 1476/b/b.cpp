#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,k;
int p[109];
ll sm[109];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",p+i),sm[i]=sm[i-1]+p[i];
		ll ans=0;
		for(int i=2;i<=n;i++)
			ans=max(ans,((ll)p[i]*100-1)/k+1-sm[i-1]);
		printf("%lld\n",ans);
	}
	return 0;
}