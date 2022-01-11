#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,s[4],ad[4];
		scanf("%d",&n);
		for(int i=0;i<4;i++)
			scanf("%d",s+i);
		int fg=0;
		for(int i=0;i<1<<4;i++)
		{
			for(int j=0;j<4;j++)
				if(i>>j&1)
					ad[j]=1;
				else
					ad[j]=0;
			int tg=1;
			for(int j=0;j<4;j++)
				if(!(s[j]>=ad[j]+ad[(j+1)%4]&&s[j]<=n-2+ad[j]+ad[(j+1)%4]))
					tg=0;
			if(tg)
				fg=1;
		}
		printf("%s\n",fg?"YES":"NO");
	}
	return 0;
}