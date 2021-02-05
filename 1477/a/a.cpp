#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
ll k;
ll s[200009];
ll gcd(ll a,ll b)
{
	if(!a||!b)
		return a+b;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",s+i);
		sort(s+1,s+n+1);
		ll g=0;
		for(int i=2;i<=n;i++)
			g=gcd(s[i]-s[i-1],g);
		if((k-s[1])%g==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}