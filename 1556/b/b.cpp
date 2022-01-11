#include<bits/stdc++.h>
using namespace std;
int n;
int s[100009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),s[i]%=2;
		int sm=0;
		for(int i=1;i<=n;i++)
			if(s[i]&1)
				sm++;
		if(n&1)
		{
			if(sm==n/2||sm==n/2+1)
			{
				int p=(sm==n/2?2:1),ans=0;
				for(int i=1;i<=n;i++)
					if(s[i]&1)
					{
						ans+=abs(i-p);
						p+=2;
					}
				printf("%d\n",ans);
			}
			else
				printf("-1\n");
		}
		else
		{
			if(sm==n/2)
			{
				int p1=1,p2=2,ans1=0,ans2=0;
				for(int i=1;i<=n;i++)
					if(s[i]&1)
					{
						ans1+=abs(i-p1);
						ans2+=abs(i-p2);
						p1+=2,p2+=2;
					}
				printf("%d\n",min(ans1,ans2));
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}