#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int vis[60],s[109];
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
		int n;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1,a;i<=2*n;i++)
		{
			scanf("%d",&a);
			if(!vis[a])
				printf("%d ",a);
			vis[a]=1;
		}
		printf("\n");
	}
	return 0;
}