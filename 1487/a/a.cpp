#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		static int s[109];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		sort(s+1,s+n+1);
		int ans=0;
		s[n+1]=0;
		for(int i=1;i<=n;i++)
			if(s[i]!=s[i+1])
			{
				ans=n-i;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}