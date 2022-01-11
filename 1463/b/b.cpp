#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	ll p[109];
	for(int i=0;i<=40;i++)
		p[i]=1LL<<i;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int s[109],ans[109];
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		for(int i=1;i<=n;i++)
			ans[i]=*(upper_bound(p,p+41,s[i])-1);
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}