#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int x[1009],y[1009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",x+i,y+i);
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		ll smx=0,smy=0;
		if(n&1)
			smx=smy=1;
		else
		{
			int md=n/2;
			smx=x[md+1]-x[md]+1;
			smy=y[md+1]-y[md]+1;
		}
		printf("%lld\n",smx*smy);
	}
	return 0;
}