#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,k;
		scanf("%d%d%d",&n,&x,&k);
		int tp=min(k/x,n);
		ll ans=(ll)n*tp-(ll)tp*(tp+1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}