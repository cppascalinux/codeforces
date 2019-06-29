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
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	b=min(b,c);
	if(b>=a)
		printf("Yes");
	else
		printf("No");
	return 0;
}