#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int s[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll sm=0;
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),sm+=s[i];
		ll tme=sm/n;
		ll ans=(sm-tme*n)*(n-sm+tme*n);
		printf("%lld\n",ans);
	}
	return 0;
}