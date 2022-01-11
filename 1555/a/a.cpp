#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[10009];
int main()
{
	int t;
	scanf("%d",&t);
	int w[4]={0,15,20,25},v[4]={0,6,8,10};
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		if(n<=6)
			printf("15\n");
		else
		{
			if(n%2==1)
				n++;
			printf("%lld\n",n/2*5);
		}
	}
	return 0;
}