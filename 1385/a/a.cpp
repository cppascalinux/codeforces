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
	int t;
	scanf("%d",&t);
	int v[10];
	while(t--)
	{
		scanf("%d%d%d",v+1,v+2,v+3);
		sort(v+1,v+3+1);
		if(v[2]!=v[3])
			printf("NO\n");
		else
			printf("YES\n%d %d %d\n",v[1],v[1],v[2]);
	}
	return 0;
}