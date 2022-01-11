#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[509],t[1009];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j+i-1<=n;j++)
			{
				// printf("n:%d m:%d i:%d j:%d\n",i,j);
				int fg=1;
				for(int k=0;k<=i-1;k++)
					if(s[j+k]!=t[1+k])
						fg=0;
				if(!fg)
					continue;
				int ls=j+i-1;
				for(int k=1;i+k<=m;k++)
					if(ls-k<1||s[ls-k]!=t[i+k])
						fg=0;
				if(fg)
					ans=1;
			}
		}
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}