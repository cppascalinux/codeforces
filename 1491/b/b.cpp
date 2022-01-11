#include<bits/stdc++.h>
using namespace std;
int n,u,v;
int s[109];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&u,&v);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		int fg=0,tg=0;
		for(int i=2;i<=n;i++)
		{
			if(s[i]>s[i-1]+1||s[i]<s[i-1]-1)
			{
				fg=1;
				break;
			}
			if(s[i]==s[i-1]+1||s[i]==s[i-1]-1)
				tg=1;
		}
		if(fg)
			printf("0\n");
		else if(tg)
			printf("%d\n",min(u,v));
		else
			printf("%d\n",v+min(u,v));
	}
	return 0;
}