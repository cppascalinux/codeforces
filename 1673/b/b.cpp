#include<bits/stdc++.h>
using namespace std;
int n;
char s[200009];
int us[30];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(us,0,sizeof(us));
		for(int i=1;i<=n;i++)
			s[i]-='a'-1,us[s[i]]++;
		int sm=0;
		for(int i=1;i<=26;i++)
			if(us[i])
				sm++;
		memset(us,0,sizeof(us));
		for(int i=1;i<=sm;i++)
			us[s[i]]++;
		int fl=0;
		for(int i=1;i<=26;i++)
			if(us[i]>1)
				fl=1;
		if(fl)
		{
			printf("NO\n");
			continue;
		}
		// printf("qwq\n");
		for(int i=sm+1;i<=n;i++)
			if(s[i]!=s[i-sm])
				fl=1;
		if(fl)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}