#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int s[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		sort(s+1,s+n+1);
		s[n+1]=2*n+10;
		s[0]=0;
		int ls=0,ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]<=s[i-1])
				s[i]++;
		for(int i=1;i<=n;i++)
			if(s[i]!=s[i-1])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}