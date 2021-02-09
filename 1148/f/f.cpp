#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int val[300009];
ll mk[300009];
int main()
{
	scanf("%d",&n);
	ll sm=0;
	for(int i=1;i<=n;i++)
		scanf("%d%lld",val+i,mk+i),sm+=val[i];
	if(sm<0)
	{
		for(int i=1;i<=n;i++)
			val[i]=-val[i];
		sm=-sm;
	}
	ll ans=0;
	for(int i=61;i>=0;i--)
	{
		ll tsm=0;
		for(int j=1;j<=n;j++)
			if(mk[j]==1LL<<i)
				tsm+=val[j];
		if(tsm>0)
		{
			// printf("i:%d\n",i);
			for(int j=1;j<=n;j++)
				if(mk[j]&(1LL<<i))
					val[j]=-val[j];
			ans+=(1LL<<i);
		}
		for(int j=1;j<=n;j++)
			if(mk[j]&(1LL<<i))
				mk[j]^=(1LL<<i);
	}
	printf("%lld",ans);
	return 0;
}