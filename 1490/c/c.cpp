#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int t;
	static ll s[10009];
	for(int i=1;i<=10000;i++)
		s[i]=(ll)i*i*i;
	scanf("%d",&t);
	while(t--)
	{
		ll x;
		scanf("%lld",&x);
		int fg=0;
		for(int i=1;(ll)i*i*i<=x;i++)
		{
			ll v=x-(ll)i*i*i;
			if(*lower_bound(s+1,s+10001,v)==v)
				fg=1;
		}
		printf("%s\n",fg?"YES":"NO");
	}
	return 0;
}