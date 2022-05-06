#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
char s[1009];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int ls=0,fl=0;
		s[0]=s[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=s[i+1]&&s[i]!=s[i-1])
				fl=1;
		}
		printf("%s\n",fl?"NO":"YES");
	}
	return 0;
}