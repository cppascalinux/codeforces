#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		int fg=0;
		for(ll s=1;s<=n;s<<=1)
			if(s==n)
				fg=1;
		printf("%s\n",fg?"NO":"YES");
	}
	return 0;
}