#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s[10];
		for(int i=1;i<=3;i++)
			scanf("%d",s+i);
		sort(s+1,s+4);
		int t=s[3]+s[2]-2*s[1];
		if(t%3!=0)
		{
			printf("NO\n");
			continue;
		}
		if(t%6==0)
		{
			s[1]-=t/6;
			if(s[1]>=0&&s[1]%3==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(t%6==3)
		{
			s[1]-=t/6+2;
			if(s[1]>=0&&s[1]%3==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}