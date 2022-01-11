#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[10009];
char ans[1009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='U')
				ans[i]='D';
			else if(s[i]=='D')
				ans[i]='U';
			else
				ans[i]=s[i];
		ans[n+1]=0;
		printf("%s\n",ans+1);
	}
	return 0;
}