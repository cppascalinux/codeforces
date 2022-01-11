#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		char s[109],t[109];
		scanf("%d",&n);
		scanf("%s",s+1);
		memcpy(t+1,s+1,n+1);
		sort(t+1,t+n+1);
		int ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]!=t[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}