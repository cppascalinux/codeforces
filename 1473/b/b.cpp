#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char s1[30],s2[30];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s1+1,s2+1);
		n=strlen(s1+1),m=strlen(s2+1);
		int ans=-1;
		for(int i=n;i>=1;i--)
			if(n%i==0&&m%i==0)
			{
				int fg=1;
				for(int j=1;j<=n;j+=i)
					if(strncmp(s1+1,s1+j,i))
						fg=0;
				for(int j=1;j<=m;j+=i)
					if(strncmp(s1+1,s2+j,i))
						fg=0;
				if(fg)
				{
					ans=i;
					break;
				}
			}
		if(ans==-1)
		{
			printf("-1\n");
			continue;
		}
		int ml=n*m/ans;
		for(int i=1;i<=ml;i++)
			printf("%c",s1[(i-1)%ans+1]);
		printf("\n");
	}
	return 0;
}