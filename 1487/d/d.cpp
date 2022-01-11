#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll ans=0;
		for(int i=3;i*i<=2*n-1;i++)
		{
			if(i&1)
			{
				int b=(i*i-1)/2,c=(i*i+1)/2;
				// printf("a:%d b:%d c:%d\n",i,b,c);
				if(b<=n&&c<=n)
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}