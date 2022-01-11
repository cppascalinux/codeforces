#include<bits/stdc++.h>
using namespace std;
int n,k;
char s[100009];
int sm[30],rep[30];
int judge()
{
	int ans=0;
	for(int i=1;i<=26;i++)
		if(sm[i])
		{
			int tl=((sm[i]-1)/k+1)*k;
			ans+=tl-sm[i];
		}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		if(n%k)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=26;i++)
			sm[i]=0;
		for(int i=1;i<=n;i++)
			s[i]-='a'-1,sm[s[i]]++;
		if(!judge())
		{
			for(int i=1;i<=n;i++)
				printf("%c",s[i]+'a'-1);
			printf("\n");
			continue;
		}
		int fgi=0,fgj=0;
		for(int i=n;i>=1;i--)
		{
			sm[s[i]]--;
			for(int j=s[i]+1;j<=26;j++)
			{
				sm[j]++;
				if(judge()<=n-i)
				{
					fgj=j;
					break;
				}
				sm[j]--;
			}
			if(fgj)
			{
				fgi=i;
				break;
			}
		}
		int rem=n-fgi;
		for(int i=1;i<=26;i++)
			if(sm[i])
			{
				int tl=((sm[i]-1)/k+1)*k;
				rep[i]=tl-sm[i];
				rem-=rep[i];
			}
			else
				rep[i]=0;
		rep[1]+=rem;
		for(int i=1;i<=fgi-1;i++)
			printf("%c",s[i]+'a'-1);
		printf("%c",fgj+'a'-1);
		for(int i=1;i<=26;i++)
			for(int j=1;j<=rep[i];j++)
				printf("%c",i+'a'-1);
		printf("\n");
	}
	return 0;
}