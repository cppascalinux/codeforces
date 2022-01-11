#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int s[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		ll ans=0;
		for(int i=2;i<=n;i++)
			ans=max(ans,(ll)s[i]*s[i-1]);
		printf("%lld\n",ans);
	}
	return 0;
}