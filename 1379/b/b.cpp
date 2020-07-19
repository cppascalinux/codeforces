#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
int l,r;
LL m;
int test(int a)
{
	int md=m%a;
	int rev=(a-md)%a;
	if(rev<=r-l)
	{
		printf("%d %d %d\n",a,l,l+rev);
		return 1;
	}
	if(md<=r-l)
	{
		if(md==m)
			return 0;
		printf("%d %d %d\n",a,l+md,l);
		return 1;
	}
	return 0;
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%lld",&l,&r,&m);
		for(int i=l;i<=r;i++)
			if(test(i))
				break;
	}
	return 0;
}