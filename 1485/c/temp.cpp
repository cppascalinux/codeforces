#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ll ans=0;
		for(int i=1;i<=100000;i++)
			ans+=max(0,min(r,l/i-1)-i);
		printf("%lld\n",ans);
	}
	return 0;
}