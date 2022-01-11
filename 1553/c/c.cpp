#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[20],t[20];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%s",t+1);
		n=10;
		int sm[2]={0};
		memcpy(s+1,t+1,10);
		int ans=10;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='?')
			{
				if(i%2==0)
					s[i]=1;
				else
					s[i]=0;
			}
			else
				s[i]-='0';
			if(s[i])
				sm[i%2]++;
			if(sm[0]>sm[1]+(n-i)/2)
				ans=min(ans,i);
		}
		memcpy(s+1,t+1,10);
		memset(sm,0,sizeof(sm));
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='?')
			{
				if(i%2==1)
					s[i]=1;
				else
					s[i]=0;
			}
			else
				s[i]-='0';
			if(s[i])
				sm[i%2]++;
			if(sm[1]>sm[0]+(n-i+1)/2)
				ans=min(ans,i);
		}
		printf("%d\n",ans);
	}
	return 0;
}