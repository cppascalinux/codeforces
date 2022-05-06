#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k;
char s[100009];
char t[10];
int bk[200];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%d",&k);
		memset(bk,0,sizeof(bk));
		for(int i=1;i<=k;i++)
		{
			scanf("%s",t+1);
			bk[t[1]]++;
		}
		int mr=0;
		for(int i=1;i<=n;i++)
			if(bk[s[i]])
				mr=i;
		if(mr==0)
		{
			printf("0\n");
			continue;
		}
		int fg=0;
		for(int i=1;i<=mr-1;i++)
			if(bk[s[i]])
				fg=1;
		if(!fg)
		{
			printf("%d\n",mr-1);
			continue;
		}
		int ls=0,ans=0;
		for(int i=1;i<=mr;i++)
			if(bk[s[i]])
			{
				if(ls>0)
					ans=max(ans,i-ls);
				else
					ans=max(ans,i-1);
				ls=i;
			}
		printf("%d\n",ans);
	}
	return 0;
}