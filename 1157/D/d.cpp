#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
int n,k;
int ans[100009];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	scanf("%d%d",&n,&k);
	int n0=n;
	// if((k<=30&&n>(1<<k)-1))
	// {
	// 	printf("NO");
	// 	// for(;;);
	// 	return 0;
	// }
	// printf("YES\n");
	int lz=0;
	n-=(ll)k*(k+1)/2;
	int tmp=n/k;
	printf("tmp:%d\n",tmp);
	for(int i=1;i<=k;i++)
		ans[i]=i+tmp;
	for(int i=2;i<=k;i++)
	{
		ans[i]+=lz;
		if(n>=(ll)(ans[i-1]*2-ans[i])*(k-i+1))
		{
			n-=(ll)(ans[i-1]*2-ans[i])*(k-i+1);
			lz+=ans[i-1]*2-ans[i];
			ans[i]=ans[i-1]*2;
			// printf("typ1\n");
		}
		else
		{
			int t=n/(k-i+1);
			ans[i]+=t;
			lz+=t;
			n-=t*(k-i+1);
			// printf("typ2\n");
		}
	}
	if(n)
		printf("NO");
	else
	{
		printf("YES\n");
		for(int i=1;i<=k;i++)
			printf("%d ",ans[i]);
	}
	// for(int i=1;i<=k;i++)
	// 	n0-=ans[i];
	// assert(n0==0);
	// for(int i=2;i<=k;i++)
	// 	assert(ans[i]<=ans[i-1]||ans[i]>ans[i-1]*2);
	return 0;
}