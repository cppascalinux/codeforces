#include<bits/stdc++.h>
using namespace std;
int n;
char s[200009];
int ans1[200009],ans2[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int sm=0;
		for(int i=1;i<=n;i++)
		{
			s[i]-='0';
			if(s[i])
				sm++;
		}
		if((sm&1)||!s[1]||!s[n])
		{
			printf("NO\n");
			continue;
		}
		int tm=0,tl=0;
		for(int i=1;i<=n;i++)
			if(s[i])
			{
				tm++;
				if(tm<=sm/2)
					ans1[i]=ans2[i]=0;
				else
					ans1[i]=ans2[i]=1;
			}
			else
			{
				tl^=1;
				ans1[i]=tl;
				ans2[i]=tl^1;
			}
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%c",ans1[i]?')':'(');
		printf("\n");
		for(int i=1;i<=n;i++)
			printf("%c",ans2[i]?')':'(');
		printf("\n");
	}
	return 0;
}