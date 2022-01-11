#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int s[109],vis[109];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		memset(vis,0,sizeof(vis));
		sort(s+1,s+n+1);
		s[0]=-1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=s[i-1])
				printf("%d ",s[i]),vis[i]=1;
		}
		for(int i=1;i<=n;i++)
			if(!vis[i])
				printf("%d ",s[i]);
		printf("\n");
	}
	return 0;
}