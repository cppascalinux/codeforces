#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int s[109];
		scanf("%d",&n);
		int fg=0,mx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s+i);
			if(s[i]<0)
				fg=1;
			mx=max(mx,s[i]);
		}
		if(fg)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n%d\n",mx+1);
		for(int i=0;i<=mx;i++)
			printf("%d ",i);
		printf("\n");
	}
	return 0;
}