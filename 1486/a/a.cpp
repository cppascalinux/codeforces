#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		ll h[109];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",h+i);
		int fg=1;
		for(int i=1;i<=n;i++)
		{
			if(h[i]<i-1)
			{
				fg=0;
				break;
			}
			h[i+1]+=h[i]-(i-1);
			h[i]=i-1;
		}
		printf("%s\n",fg?"YES":"NO");
	}
	return 0;
}