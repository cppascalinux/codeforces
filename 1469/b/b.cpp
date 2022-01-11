#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		int s1[109],s2[109];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s1+i);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",s2+i);
		int mx1=0,mx2=0;
		s1[0]=s2[0]=0;
		for(int i=1;i<=n;i++)
			s1[i]+=s1[i-1],mx1=max(mx1,s1[i]);
		for(int i=1;i<=m;i++)
			s2[i]+=s2[i-1],mx2=max(mx2,s2[i]);
		printf("%d\n",mx1+mx2);
	}
	return 0;
}