#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
#ifdef I_LOVE_KTY
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int n,a,x,b,y;
	scanf("%d%d%d%d%d",&n,&a,&x,&b,&y);
	if(a==b)
		return printf("YES"),0;
	while(1)
	{
		a=a%n+1,b=(b-2+n)%n+1;
		if(a==b)
			return printf("YES"),0;
		if(a==x||b==y)
			break;
	}
	printf("NO");
	return 0;
}